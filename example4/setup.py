
import os
from distutils.core import setup, Extension

os.environ["CFLAGS"] = " -O0 -g -Wall "
module1 = Extension('xh',
                    sources=['xh.c', 'xhlist.c'])

setup(name='PackageName',
      version='1.0',
      description='This is a xh package',
      ext_modules=[module1])
