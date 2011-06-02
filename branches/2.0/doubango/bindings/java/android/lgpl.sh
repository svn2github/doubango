#!/bin/bash
# Build tinyWRAP for Google Android Systems

# GPL parameters
export LGPL_PARAMS="LICENSE=lgpl FFMPEG=yes H264=no THEORA=yes OPENCORE_AMR=yes SPEEX_DSP=yes SPEEX_JB=yes SPEEX_RESAMPLER=yes SPEEX_DENOISE=no SPEEX=yes ILBC=yes LIBGSM=yes G729=yes"

for IS_NEON in no yes
do
../bindings/java/android/buildAll.sh $@ NEON=$IS_NEON $LGPL_PARAMS
done

