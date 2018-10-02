#ifndef SUM_OF_VECTORS_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const vector<string> operator + ( const vector<string>& vec1, const vector<string>& vec2 )
{
    vector<string>vecToReturn;
    
    for( int i = 0; i < vec1.size(); i++ )
    {
        string numberToPush = vec1[i] + " " + vec2[i];
        
        vecToReturn.push_back( numberToPush );
    }
    
    return vecToReturn;
}

#endif // SUM_OF_VECTORS
