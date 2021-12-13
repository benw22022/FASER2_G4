# FASER2_G4

This package creates simple G4 geometries for FASER2 sensitivity studies.
Before setting this up you need to be able to create HepMC files using my modified [FORESEE package](https://github.com/joshmcfayden/FORESEE).

The HepMC files are passed to G4 via the `/generator/hepmcAscii/open` flag - see later for more details.



## Install/setup up Geant4 MacOS


### Install G4:

Get source code and make build directory

```bash
wget http://cern.ch/geant4-data/releases/geant4.10.07.p02.tar.gz
tar xvzf geant4.10.07.p02.tar.gz
mkdir geant4.10.07-build
cd geant4.10.07-build
```

Get initial CMake files:

```bash
cmake -DCMAKE_INSTALL_PREFIX=/Users/mcfayden/Work/FASER/FASER2/G4_v2/geant4.10.07.p02-install -DGEANT4_USE_OPENGL_X11=ON -DGEANT4_INSTALL_DATA=ON -DXQuartzGL_INCLUDE_DIR=/usr/X11R6/include -DXQuartzGL_gl_LIBRARY=/usr/X11R6/lib/libGL.dylib -DXQuartzGL_glu_LIBRARY=/usr/X11R6/lib/libGLU.dylib /Users/mcfayden/Work/FASER/FASER2/G4_v2/geant4.10.07.p02
```

Then edit to get X11 consistently from one place:
```bash
sed -i'' -e $'/X11/s:/usr/local:/usr/X11R6:g' ../geant4.10.07-build/CMakeCache.txt
```

Run cmake and compile
```bash
cmake -DCMAKE_INSTALL_PREFIX=/Users/mcfayden/Work/FASER/FASER2/G4_v2/geant4.10.07.p02-install -DGEANT4_USE_OPENGL_X11=ON -DGEANT4_INSTALL_DATA=ON -DXQuartzGL_INCLUDE_DIR=/usr/X11R6/include -DXQuartzGL_gl_LIBRARY=/usr/X11R6/lib/libGL.dylib -DXQuartzGL_glu_LIBRARY=/usr/X11R6/lib/libGLU.dylib -DGEANT4_USE_QT=ON -DCMAKE_PREFIX_PATH=/usr/local//Cellar/qt@5/5.15.2/lib/cmake/ /Users/mcfayden/Work/FASER/FASER2/G4_v2/geant4.10.07.p02

make 
make install
```

Test simple build:
```bash
cp -r geant4.10.07.p02/examples/basic/B1 .	
mkdir B1-build
cd B1-build
cmake ../B1
./exampleB1
```


### Install HepMC and test building G4 executable against it

For everything here I have used HepMCv2.06 installed via Rivet: see [here](https://gitlab.com/hepcedar/rivet/-/blob/release-3-1-x/doc/tutorials/installation.md).


Test HepMC G4 build:
```bash
cp -r geant4.10.07.p02/examples/extended/eventgenerator/HepMC/HepMCEx01 .
mkdir HepMCEx01-build
cd HepMCEx01-build
cmake -DHEPMC_LIBRARIES=/Users/mcfayden/Work/ATLAS/mcgen/HepMC-2.06.11-build/lib/libHepMC.dylib -DHEPMC_INCLUDE_DIR=/Users/mcfayden/Work/ATLAS/mcgen/HepMC-2.06.11/ ../HepMCEx01
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
```


All the main things to control can be edited from the `newGeo/src/ExN04DetectorParameterDef.icc` file.
TODO: Make this configurable from macro file.

For example magnet geometry is controlled by:
```cpp
fmagcase_rmax =  130.*cm;
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
mkdir newGeo-build
cd newGeo-build
cp FASER2_HepMC_v4_FASER2_Default_1stTrkStation-build/*.in FASER2_HepMC_v4_FASER2_Default_1stTrkStation-build/*.mac .
cmake -DHEPMC_LIBRARIES=/Users/mcfayden/Work/ATLAS/mcgen/HepMC-2.06.11-build/lib/libHepMC.dylib -DHEPMC_INCLUDE_DIR=/Users/mcfayden/Work/ATLAS/mcgen/HepMC-2.06.11/ ../FASER2_HepMC_v4_FASER2_Default_1stTrkStation
```

And now we are finally ready to run!

To run just a few events and see the visualisation:
```bash
./newGeo 
```



