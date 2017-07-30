/* Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), 
return 964176192 (represented in binary as 00111001011110000010100101000000). */


// My solution
uint32_t reverseBits(uint32_t n) {
    vector<bool> ref(32,false);
    int i = 0;
    while(n)
    {   ref[i] = (n%2==1);
        n = n >> 1;
        i++;
    }
    
    uint32_t num = 0;
    for (i = 0; i<ref.size(); i++)
    {   
        if(ref[i])
            num += pow(2, 31-i);
    }
    
    return num;
}

// Optimal solution
uint32_t  reverseBits(uint32_t n) {
    uint32_t result= 0;
    for(int i=0; i<32; i++)
        result = (result<<1) + (n>>i &1);
    
    return result;
}