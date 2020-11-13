/*
One person can bribe at most two others
return minimum number of bribes that took place to get the queue into its current state!
*/

/* Solution
Since the question only asks the number of bribes, 
there's no need to really do a sorting, nor element swapping, nor "bubbling up" an element. 
All you need to do is to count the number of people who overtake a person.
*/ 

void minimumBribes(vector<int> q) {
    int N = q.size();
    int bribes = 0;
    for (int i=0; i<N; i++) {
        int id = q[i];
        if (id-1 > i+2) {
            cout << "Too chaotic" << endl;
            return;
        }
        for (int j=std::max(0, id-2); j<i; j++) {
            if (q[j] > id) bribes += 1;
        }
    }
    cout << bribes << endl;
}
