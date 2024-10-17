# FASER2_G4

This package creates simple G4 geometries for FASER2 sensitivity studies.
Before setting this up you need to be able to create HepMC files using my modified [FORESEE package](https://github.com/joshmcfayden/FORESEE).

The HepMC files are passed to G4 via the `/generator/hepmcAscii/open` flag - see later for more details.

## Install/setup up Geant4 on lxplus (tested with LCG_101 view)

Setup G4 and enviroment from LCG:

```bash
source /cvmfs/sft.cern.ch/lcg/views/LCG_101/x86_64-centos7-gcc10-opt/setup.sh
```

Get FASER2 G4 geometry and create "newGeo" version:

```bash
git clone https://github.com/joshmcfayden/FASER2_G4.git
cp -r FASER2_G4/FASER2_HepMC_v4_FASER2_Default_1stTrkStation newGeo
cd newGeo
mv FASER2_HepMC_v4_FASER2_Default_1stTrkStation.cc newGeo.cc
sed -i 's/FASER2_HepMC_v4_FASER2_Default_1stTrkStation/newGeo/g' *.*
```

Create build directory and compile:

```bash
cd ..
mkdir newGeo-build
cd newGeo-build
cmake -DCMAKE_BUILD_TYPE=Debug ../newGeo
make
```

Test run:

```bash
cp ../FASER2_G4/FASER2_HepMC_v4_FASER2_Default_1stTrkStation-build/* .
./newGeo hepmc_ascii.in
```

Once compiled, to just run for every new login you just need the following setup line:

```bash
source /cvmfs/sft.cern.ch/lcg/views/LCG_101/x86_64-centos7-gcc10-opt/setup.sh
```

## Install/setup up Geant4 on lxplus

You simply need to setup an LCG view:

```bash
source /cvmfs/sft.cern.ch/lcg/views/LCG_105/x86_64-el9-gcc11-opt/setup.sh
```

## Running Geant4 with Docker

Geant4 can be a massive pain to set up and install on your own machine. An easier solution is to run Geant4 through a Docker container which has access to `cvmfs`. A git repository which contains instructions and scripts for running el9 docker container with `cvmfs` access can be found here [github.com/benw22022/el9-cvmfs-docker](https://github.com/benw22022/el9-cvmfs-docker/tree/master). This setup so far has been tested on Ubuntu-20.04 (running in WSL2) and on Mac OS. Mac users please read instructions carefully as there are a number of steps to get x11 forwarding working properly - you may need to restart your laptop multiple times.

Once you have repository cloned, followed the steps to install docker and have enabled x11 forwarding you can start the container by doing:

```bash
./run_container.sh /path/to/FASER2_G4
```

This will start the container and mount the path to your `FASER2_G4` directory to the home directory of the container and mount `cvmfs`. *NOTE:* the files and folders within `/path/to/FASER2_G4` will be the *only* ones visible within the container. Any files created outside the container's home directory will not be saved on exit; neither will any changes to the environment.

Once within the container you can obtain Geant4 by setting up an LCG release as you would on lxplus

```bash
source /cvmfs/sft.cern.ch/lcg/views/LCG_105/x86_64-el9-gcc11-opt/setup.sh
```

## Install/setup up Geant4 on MacOS (tested on 11.4)

### Install G4:

Get source code and make build directory

```bash
wget http://cern.ch/geant4-data/releases/geant4.10.07.p02.tar.gz\ntar xvzf geant4.10.07.p02.tar.gz\nmkdir geant4.10.07-build\ncd geant4.10.07-build
mkdir geant4.10.07.p02-build
cd geant4.10.07.p02-build
```

Get initial CMake files:

```bash
cmake -DCMAKE_INSTALL_PREFIX=../geant4.10.07.p02-install -DGEANT4_USE_OPENGL_X11=ON -DGEANT4_INSTALL_DATA=ON -DXQuartzGL_INCLUDE_DIR=/usr/X11R6/include -DXQuartzGL_gl_LIBRARY=/usr/X11R6/lib/libGL.dylib -DXQuartzGL_glu_LIBRARY=/usr/X11R6/lib/libGLU.dylib ../geant4.10.07.p02
```

Then edit to get X11 consistently from one place:
```bash
sed -i'' -e $'/X11/s:/usr/local:/usr/X11R6:g' CMakeCache.txt
```

Run cmake and compile
```bash
cmake -DCMAKE_INSTALL_PREFIX=../geant4.10.07.p02-install -DGEANT4_USE_OPENGL_X11=ON -DGEANT4_INSTALL_DATA=ON -DXQuartzGL_INCLUDE_DIR=/usr/X11R6/include -DXQuartzGL_gl_LIBRARY=/usr/X11R6/lib/libGL.dylib -DXQuartzGL_glu_LIBRARY=/usr/X11R6/lib/libGLU.dylib -DGEANT4_USE_QT=ON -DCMAKE_PREFIX_PATH=/usr/local//Cellar/qt@5/5.15.2/lib/cmake/ ../geant4.10.07.p02
make 
make install
```

Setup environment:
```
cd ../geant4.10.07.p02-install/bin
source geant4.sh
cd ../../
```

Test simple build:
```bash
cp -r geant4.10.07.p02/examples/basic/B1 .
mkdir B1-build
cd B1-build
cmake ../B1
make
./exampleB1
cd ..
```


### Install HepMC and test building G4 executable against it

For everything here I have used HepMCv2.06 installed via Rivet: see [here](https://gitlab.com/hepcedar/rivet/-/blob/release-3-1-x/doc/tutorials/installation.md).

NASTY HACK ALERT: For some reason, to get this to compile I have to change `#include <math.h>` to `#include </Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/math.h>` in `/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/v1/cmath` otherwise `math.h` gets sourced from somewhere else instead...

You may also need to run:
```bash
sudo xcode-select -s /Applications/Xcode.app/Contents/Developer
```

Test HepMC G4 build:
```bash
cp -r geant4.10.07.p02/examples/extended/eventgenerator/HepMC/HepMCEx01 .
mkdir HepMCEx01-build
cd HepMCEx01-build
cmake -DHEPMC_LIBRARIES=/Users/mcfayden/Work/ATLAS/mcgen/HepMC-2.06.11-build/lib/libHepMC.dylib -DHEPMC_INCLUDE_DIR=/Users/mcfayden/Work/ATLAS/mcgen/HepMC-2.06.11/ ../HepMCEx01
make
./HepMCEx01 hepmc_ascii.in
```

### Each new session
```bash
cd geant4.10.07.p02-install/bin
source geant4.sh
cd -
```

## Build FASER2 geometry:

Start by copying the `FASER2_HepMC_v4_FASER2_Default_1stTrkStation` source folder to a new folder, e.g. `newGeo`.
```bash
cp -r FASER2_HepMC_v4_FASER2_Default_1stTrkStation newGeo
cd newGeo
mv FASER2_HepMC_v4_FASER2_Default_1stTrkStation.cc newGeo.cc
sed -i '' -e 's/FASER2_HepMC_v4_FASER2_Default_1stTrkStation/newGeo/g' *.*
```


All the main things to control can be edited from the `ExN04DetectorParameterDef.icc` and `ExN04Field.cc` files.
TODO: Make this configurable from macro file.

For example magnet geometry is controlled in `newGeo/src/ExN04DetectorParameterDef.icc` by changing:
```cpp
fmagcase_rmax =  130.*cm; // doesn't matter what value this is it's only used for visualisation 
fmag_rmax =  100.*cm;

fmag1_dz =  5.*m;
fmag1_locz = 0;

fmag2_dz =  2.5*m;
fmag2_locz = 5.5*m;

fmag3_dz =  2.5*m;
fmag3_locz = 8.5*m;
```

And then the magnetic field strengths are controlled in `newGeo/src/ExN04Field.cc` by:
```cpp
  fBx = 1*tesla;
```

Once you have the geometry and magnetic fields you want you can compile:
```bash
cd ..
mkdir newGeo-build
cd newGeo-build
cp ../FASER2_HepMC_v4_FASER2_Default_1stTrkStation-build/*.in ../FASER2_HepMC_v4_FASER2_Default_1stTrkStation-build/*.mac .
cmake -DHEPMC_LIBRARIES=<PATH TO HEPMC>/lib/libHepMC.dylib -DHEPMC_INCLUDE_DIR=<PATH TO HEPMC> ../newGeo
make
```

And now we are finally ready to run!

To run just a few events of a HepMC file and keep the visualisation open do:
```bash
./newGeo
```

To run over 1M events in HepMC file and close the visualisation do:
```bash
./newGeo foresee_hepmc_ascii_1M.in
```

Note that the input location of the HepMC file is given by this line in `foresee_hepmc_ascii.in`/`foresee_hepmc_ascii_1M.in`:
```
/generator/hepmcAscii/open /Users/mcfayden/Work/FASER/FASER2/FORESEE/output_faser2_D2_L5_Z480.hepmc
```

The output of this run is stored in a ROOT ntuple with filename `output.root` and tree `Hits` which contains the positive and negatively charged electron 4-momenta for specific plane in the z-direction (in this example the position of the 1st tracker station).

## Changing magnetic field strength from macro

The default magnetic field strength is 1 tesla, but you can specify the magnetic field in the steering macro by adding the line

```bash
/det/magnetField <your-value> tesla
```

***Note:*** The implemented messenger class is a bit janky, but is functional. I plan to update the code in future to do this better.
