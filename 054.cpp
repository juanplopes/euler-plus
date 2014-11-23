#include <iostream>
#include <vector>
#include <algorithm>
#define ull unsigned long long
using namespace std;

int value(string s) {
    char c = s[0];
    if (c>='0' and c<='9') return c-'0';
    if (c=='T') return 10;
    if (c=='J') return 11;
    if (c=='Q') return 12;
    if (c=='K') return 13;
    if (c=='A') return 14;
    return -1000;
}

bool are_same_suit(vector<string> cards) {
    for(int i=1; i<cards.size(); i++)
        if (cards[i][1] != cards[i-1][1])
            return false;
    return true;
}

ull total_value(vector<string> cards) {
    int answer = 0;
    for(int i=0; i<cards.size(); i++)
        answer = answer * 20 + value(cards[i]);
    return answer;        
}

ull is_royal_flush(vector<string> hand) {
    int count = 0;
    for(int i=0; i<hand.size(); i++)
        if (value(hand[i]) >= 10)
            count++;
    return count==5 and are_same_suit(hand);
}

ull is_straight(vector<string> hand) {
    for(int i=1; i<hand.size(); i++)
        if (value(hand[i])-value(hand[i-1]) != -1 and (i!=1 or hand[0][0] != 'A' or hand[1][0] != '5'))
            return 0;
            
    if (hand[0][0] == 'A' and hand[1][0] == '5')
        return value(hand[1]);
    else
        return value(hand[0]);
}

ull is_flush(vector<string> hand) {
    return are_same_suit(hand);
}

ull is_straight_flush(vector<string> hand) {
    if (is_flush(hand))
        return is_straight(hand);
    return 0;
}

ull is_four_of_a_kind(vector<string> hand) {
    for(int i=0; i<15; i++) { 
        int count = 0;
        for(int j=0; j<hand.size(); j++)
            if (value(hand[j]) == i)
                count++;
        if (count == 4)
            return i;
    }
    return 0;
}

ull is_three_of_a_kind(vector<string> hand) {
    for(int i=0; i<15; i++) { 
        int count = 0;
        for(int j=0; j<hand.size(); j++)
            if (value(hand[j]) == i)
                count++;
        if (count == 3)
            return i;
    }
    return 0;
}

ull is_one_pair(vector<string> hand) {
    for(int i=0; i<15; i++) { 
        int count = 0;
        for(int j=0; j<hand.size(); j++)
            if (value(hand[j]) == i)
                count++;
        if (count == 2)
            return i;
    }
    return 0;
}

ull is_full_house(vector<string> hand) {
    int first = 0;
    for(int i=0; i<15; i++) { 
        int count = 0;
        for(int j=0; j<hand.size(); j++)
            if (value(hand[j]) == i)
                count++;
        if (count == 3) {
            first = i;
            break;
        }
    }
    if (first==0) return 0;
    for(int i=0; i<15; i++) { 
        if (i==first) continue;
        int count = 0;
        for(int j=0; j<hand.size(); j++)
            if (value(hand[j]) == i)
                count++;
        if (count == 2) {
            return first*20+i;
            break;
        }
    }
    return 0;
}

ull is_two_pairs(vector<string> hand) {
    int first = 0;
    for(int i=14; i>=0; i--) { 
        int count = 0;
        for(int j=0; j<hand.size(); j++)
            if (value(hand[j]) == i)
                count++;
        if (count == 2) {
            first = i;
            break;
        }
    }
    if (first==0) return 0;
    for(int i=0; i<15; i++) { 
        if (i==first) continue;
        int count = 0;
        for(int j=0; j<hand.size(); j++)
            if (value(hand[j]) == i)
                count++;
        if (count == 2) {
            return first*20+i;
        }
    }
    return 0;
}

int won(ull a, ull b, vector<string> A, vector<string> B) {
    if (a==0 && b==0) return 0;
    //cout << " " << a << " " << b << endl;
    if (a==b) return total_value(A) > total_value(B) ? 1 : 2;
    return a>b?1:2;
}

int won(vector<string> A, vector<string> B) {
    int x;
    if ((x = won(is_royal_flush(A), is_royal_flush(B), A, B)) != 0) return 10 + x;
    if ((x = won(is_straight_flush(A), is_straight_flush(B), A, B)) != 0) return 20 + x;
    if ((x = won(is_four_of_a_kind(A), is_four_of_a_kind(B), A, B)) != 0) return 30 + x;
    if ((x = won(is_full_house(A), is_full_house(B), A, B)) != 0) return 40 + x;
    if ((x = won(is_flush(A), is_flush(B), A, B)) != 0) return 50 + x;
    if ((x = won(is_straight(A), is_straight(B), A, B)) != 0) return 60 + x;
    if ((x = won(is_three_of_a_kind(A), is_three_of_a_kind(B), A, B)) != 0) return 70 + x;
    if ((x = won(is_two_pairs(A), is_two_pairs(B), A, B)) != 0) return 80 + x;
    if ((x = won(is_one_pair(A), is_one_pair(B), A, B)) != 0) return 90 + x;
    if ((x = won(total_value(A), total_value(B), A, B)) != 0) return 100 + x;
    return 0;
}

bool highest(string a, string b) {
    return value(a) > value(b);
}

int main() {
    int cases; cin >> cases;
    string s;
    while(cases--) {
        vector<string> A, B;
        for(int i=0; i<5; i++) { cin >> s; A.push_back(s); }
        for(int i=0; i<5; i++) { cin >> s; B.push_back(s); }
        
        sort(A.begin(), A.end(), highest);
        sort(B.begin(), B.end(), highest);
        
        cout << "Player " << won(A, B)%10 << endl;
    }

}

