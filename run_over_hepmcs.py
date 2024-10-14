import glob
import os
import argparse
import sys

def write_macro(hepmcfile, magnetic_field=100, nevents=1000, macro_name="proc_hepmc.in"):
    
    file_contents = f"\
    # /control/execute vis.mac\n\
    /vis/scene/add/magneticField {magnetic_field}\n\
    /generator/select hepmcAscii\n\
    /generator/hepmcAscii/open {hepmcfile}\n\
    /generator/hepmcAscii/verbose 0\n\
    /run/beamOn {nevents}"
    
    with open(macro_name, 'w') as macro:
        macro.write(file_contents)


def main(g4build_dir, input_dir, output_dir, bfield_strength):
    
    hepmc_files = glob.glob(os.path.join(input_dir, "*.hepmc"))
    
    os.makedirs(output_dir, exist_ok=True)
    
    os.chdir(g4build_dir)
    
    for hepmc in hepmc_files:
        write_macro(hepmc, bfield_strength)
        print(f"Processesing {hepmc}...")
        
        os.makedirs("logs", exist_ok=True)
        logfile_name = os.path.join("logs", f'B{bfield_strength:.3f}_{os.path.basename(hepmc).replace(".hepmc", ".log")}')
        
        os.system(f"./FASER2_HepMC_v4_FASER2_Cavern_Rect_Baseline_Bhoriz_AllTrkStations proc_hepmc.in > {logfile_name} 2>&1") #TODO: Don't hard-code this
        # os.system(f"./FASER2_HepMC_v4_FASER2_Cavern_Rect_Baseline_Bhoriz_AllTrkStations proc_hepmc.in | tee {logfile_name}") #TODO: Don't hard-code this

        if not os.path.exists("output.root"):
            print(f"ERROR: No output.root file found when processesing {hepmc}. Check logfile: {logfile_name}")
            continue
        
        new_output_filepath = os.path.join(output_dir, f'B{bfield_strength:.3f}_{os.path.basename(hepmc).replace(".hepmc", ".root")}')
        os.system(f"mv output.root {new_output_filepath}")
        
        if os.path.exists(new_output_filepath):
            print(f"Created {new_output_filepath}")
        else:
            print("Error in moving root file output")
        
if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("g4build", help='geant4 app build directory')
    parser.add_argument("input", help='input directory')
    parser.add_argument("output", help='output directory')
    parser.add_argument("-bfield", help='Magnetic field strength', default=100)
    
    args = parser.parse_args()
    
    main(os.path.abspath(args.g4build), os.path.abspath(args.input), os.path.abspath(args.output), args.bfield)
    
    