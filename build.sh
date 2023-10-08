SOURCE_FILE="main.cpp"
OUTPUT_EXECUTABLE="AHEC"


CXX="g++"
CXXFLAGS=""


LDFLAGS=""


rm -f "$OUTPUT_EXECUTABLE"


$CXX $CXXFLAGS $LDFLAGS -o "$OUTPUT_EXECUTABLE" "$SOURCE_FILE"


if [ $? -eq 0 ]; then
  echo "Build successful! Executable: $OUTPUT_EXECUTABLE"
else
  echo "Build failed."
fi
