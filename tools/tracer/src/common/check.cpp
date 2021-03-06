/*
#
# ----------------------------------------------------------------------------
#
# Copyright 2019 IBM Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# ----------------------------------------------------------------------------
#
*/
#include "check.h"

#include <stdio.h>
#include <stdlib.h>
#include <execinfo.h>

void cxtrace::backtrace() {
    void *callstack[128];
    int frames = ::backtrace(callstack, 128);
    char **strs = backtrace_symbols(callstack, frames);
    for (int i = 2; i < frames; ++i) {
        fprintf(stderr, "(%d)  %s\n", i-2, strs[i]);
    }
    free(strs);
}
