"""
HepMC2 -> HepMC3 converter helper
---------------------------------------------------------------------------------------------
A little helper script to convert HepMC2 files to the HepMC3 standard
"""


import os
import glob
import argparse

def main(args):
    
    input_files = glob.glob(os.path.join(args.input, "*.hepmc"))
    
    if len(input_files) == 0:
        print(f"Error: No hepmc files found on path: {args.input}")
        return 1
        
    os.makedirs(args.output, exist_ok=True)
    
    for i, fpath in enumerate(input_files):
        new_fpath = os.path.join(args.output, os.path.basename(fpath))
        os.system(f"./{args.exe} -i hepmc2 -o hepmc3 {fpath} {new_fpath} &> /dev/null")
        print(f"{i+1} / {len(input_files)}: Written {new_fpath}")
    
    print("Done")
    
if __name__ == "__main__":
    
    
    parser = argparse.ArgumentParser()
    parser.add_argument("exe", help='path to hepmc converter exe')
    parser.add_argument("input", help='input directory')
    parser.add_argument("output", help='output directory')
    
    args = parser.parse_args()
    
    main(args)