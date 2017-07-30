/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5*/

int countSegments(string s) {
    int seg=0,i=0;
    bool curSeg=false;
    
    while (i<s.size())
    {
        if (s[i]!= ' ' &&!curSeg)
        {
            curSeg=true;
            seg++;
            
        }
        else if (s[i] == ' ')
            curSeg=false;
        i++;
    }
    

    return seg;
}