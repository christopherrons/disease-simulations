# Create MakeFile
cmake -Bbuild -H.

# Compile using make
cd build
make

# Execute the app
cd ../bin
./disease_simulations

# Return to previous
cd -