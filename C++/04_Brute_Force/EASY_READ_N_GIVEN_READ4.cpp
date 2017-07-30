/* The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
Note:
The read function will only be called once for each test case.
*/

int read(char *buf, int n) 
{	int count = 0,  // count - intermediate number of characters read from read4
	int pos = 0;	// pos - total number of characters read from file
    char tmp[4];	// intermediate buffer is read into this
    while (pos < n) 
    {
        count = read4(tmp);
        count = min(count, n - pos);	// n - pos is the remaining number of characters to read
        for (int i = 0; i < count; i++) 
            buf[pos++] = tmp[i];
        

        if(count < 4) break;	// eof reached
    }
    
    return pos;
 }


// Case where read() may be called multiple times.
// Think that you have 4 chars "a, b, c, d" in the file, and you want to call your function twice like this:
// read(buf, 1); // should return 'a'
// read(buf, 3); // should return 'b, c, d'
// All the 4 chars will be consumed in the first call. 
// So the tricky part of this question is how can you preserve the remaining 'b, c, d' to the second call.

class Read4
{
public:
	char tmp4[4];
	int pos4, count4;

	Read4()
	{
		pos4 = 0;	// Corresponds to position in internal buffer
		count4 = 0;	// Corresponds to the previous count of characters returned
	}

	int read(char* buf, int n) 
	{   int pos = 0;	// Corresponds to position in final buffer
	    while (pos < n) 	
	    {   // If cache needs to be refreshed
	        if (pos4 >= count4)  // If the writing has been done -> cache has been written
	        {     
	            pos4 = 0;
	            count4 = read4(tmp4);
	            if (count4 == 0) break;
	        }
	        buf[pos++] = tmp4[pos4++];
	    }
	    return pos;
	}
}


