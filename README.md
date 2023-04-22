# CacheSimulator

How to run it:
Create a folder that contains cache_sim.cpp and input.txt. Input.txt should contain only integers separated by one space each. 

-Build the executable with this command
        g++ -o cacheSim cache_sim.cpp
        
-Run the executable with this command
        ./cacheSim <numEntries> <associativity> input.txt
        
-numEntries: an int that is a power of two which designates the size of the cache

-associativity: an int that is a power of two less than or equal to numEntries that specifies how many blocks will be used in the cache.

How it works:
This program simulates a cpu cache with a specified size (numEntries) and a specified associativity aka number of blocks (associativity). The cache contents are stored in a vector of size numEntries. The cache vector is immediately initialized to have every index = -1. The current index of each block is also stored in an array of size numEntries / associativity, called blockSpace. This array is used to keep track of the index of each block, this is to maintain a FIFO replacement policy in each block. This array is initialized to 0. Each entry is read, then classified to a block (section) by modding entry with associativity. The block is then itterated through to check if the data is already present. If the data is found, a HIT is reported. If the data is not found, the data is placed at the current block index of its designated block/section. The block index is incremented and modded by blockSpace to wrap around and not leak into other blocks. This is done for the entire input file, and recorded in the output file (cache_sim_output.txt).
