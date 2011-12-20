#!/bin/bash
#$Id: setignores.sh 6220 2011-11-16 09:51:36Z jabriffa $

# top-level folders for libraries and targets
for folder in Libraries SimCommsys Steganography Windows; do
   echo "*** $folder"
   propval=[Dd]ebug$'\n'[Rr]elease$'\n'[Pp]rofile$'\n'*.suo$'\n'*.ncb$'\n'*cache.dat
   svn ps svn:ignore "$propval" $folder
   #svn pg svn:ignore $folder
   # individual folders for libraries and targets
   for target in $folder/*; do
      echo "*** $target"
      propval=[Dd]ebug$'\n'[Rr]elease$'\n'[Pp]rofile$'\n'*.vcproj.*.user
      svn ps svn:ignore "$propval" $target
      #svn pg svn:ignore $target
   done
done
