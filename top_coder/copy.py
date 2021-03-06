import pyperclip
import sys


def replace_file(f):
  b = ""
  for line in f.readlines():
    if "competitions.utils" in line:
      util = open(ROOT + "/" + line.split()[1].replace(".", "/") + ".py")
      b = b + replace_file(util)
    elif "int main" in line:
      break
    else:
      b = b + line
  return b


ROOT = "/home/maxnelso/Dropbox"

if __name__ == "__main__":
  if len(sys.argv) <= 1:
    print "Pass in the filename"
    sys.exit(0)
  f = open(sys.argv[1])
  pyperclip.copy(replace_file(f))

