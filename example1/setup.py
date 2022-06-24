# -*- coding:utf-8 -*-
# Author: lamborghini1993
# Date: 2022-06-23 22:05:56
"""

"""

from distutils.core import setup, Extension

setup(
    name='test1',
    version='1.0',
    description="python interface test1 c library function",
    author="lambor",
    ext_modules=[Extension('test1', ['test1.c'])]
)

print "-----build---done--------------"
