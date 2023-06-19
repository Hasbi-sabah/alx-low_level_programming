#!/bin/bash
curl -s -o /tmp/rand.so https://raw.githubusercontent.com/Hasbi-sabah/alx-low_level_programming/master/0x18-dynamic_libraries/rand.so
export LD_PRELOAD=/tmp/rand.so
