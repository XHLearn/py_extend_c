# -*- coding:utf-8 -*-
# Author: lamborghini1993
# Date: 2022-06-23 23:01:55
"""
gcc -fPIC foo.c -o foo.so -shared  -I/usr/include/python2.7
"""

import foo
print foo
print foo.__dict__
print dir(foo)
print foo.foo_bar()
print foo.add(11, 5)
