int hIndex(vector<int>& citations) {
    int n = citations.size();
    if (n==0) return 0;
    for (int i = 0; i<n; i++)
    {   int h = n-i;
        if (citations[i]>=h) return h;
    }
    return 0;
}11