# -*- coding: utf-8 -*-
from netcacrypto import *
import sys

arg_count=len(sys.argv)

if arg_count!=1:
    print("Usage: python info.py")
    sys.exit(-1)

#获取版本信息
print("version:\t"+get_version())
#获取配置信息
print("config:\n"+get_config())
#获取错误号
print("last error:\t"+str(get_last_error()))
#获取错误信息
print("error msg\t"+get_error_msg(get_last_error()))