import argparse


parser = argparse.ArgumentParser(prog='bracket transformer', description='tranform [] to \{\}')
parser.add_argument('-i', '--input', default="in.txt")
parser.add_argument('-o', '--output', default="out.txt")
args = parser.parse_args()

in_file = args.input
out_file = args.output

txt = ""
with open(in_file, "r") as f:
    for line in f.readlines():
        txt += line.replace("[", "{").replace("]", "}")
with open(out_file, "w") as f:
    f.write(txt)
