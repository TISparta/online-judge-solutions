#include <bits/stdc++.h>

using namespace std;

const int N_CARDS = 5, LEN = 3;

int ans;
char card[LEN];
vector < pair <int, char> > hand (N_CARDS), deck(N_CARDS), bestHand(N_CARDS);

void print() {
    printf("Best hand: ");
    if (ans == 0) puts("highest-card");
    if (ans == 1) puts("one-pair");
    if (ans == 2) puts("two-pairs");
    if (ans == 3) puts("three-of-a-kind");
    if (ans == 4) puts("straight");
    if (ans == 5) puts("flush");
    if (ans == 6) puts("full-house");
    if (ans == 7) puts("four-of-a-kind");
    if (ans == 8) puts("straight-flush");
}

bool straightFlush() {
    int sc = bestHand[0].second;
    for (int i = 1; i < N_CARDS; i++)
        if (bestHand[i].second != sc) return false;
    vector <int> tmp(N_CARDS);
    for (int i = 0; i < N_CARDS; i++) tmp[i] = bestHand[i].first;
    sort(tmp.begin(), tmp.end());
    if (tmp == vector <int> {1, 10, 11, 12, 13}) return true;
    for (int i = 1; i < N_CARDS; i++)
        if (tmp[i] - tmp[i - 1] != 1) return false;
    return true;
}

bool fourOfaKind() {
    int fs = bestHand[0].first, ct = 1;
    for (int i = 1; i < N_CARDS; i++)
        if (bestHand[i].first == fs) ct++;
    if (ct == 4) return true;
    fs = bestHand[1].first, ct = 0;
    for (int i = 0; i < N_CARDS; i++)
        if (bestHand[i].first == fs) ct++;
    return (ct == 4);
}

bool fullHouse() {
    int val1 = -1, val2 = -1;
    val1 = bestHand[0].first;
    for (int i = 1; i < N_CARDS; i++)
        if (bestHand[i].first != val1)
            val2 = bestHand[i].first;
    if (val2 == -1) return false;
    int ct1 = 0, ct2 = 0;
    for (int i = 0; i < N_CARDS; i++) {
        if (bestHand[i].first == val1) ct1++;
        if (bestHand[i].first == val2) ct2++;
    }
    return ((ct1 == 3 and ct2 == 2) or (ct1 == 2 and ct2 == 3));
}

bool flush() {
    int sc = bestHand[0].second;
    for (int i = 1; i < N_CARDS; i++)
        if (bestHand[i].second != sc) return false;
    return (not straightFlush());
}

bool straight() {
    bool ok = true;
    vector <int> tmp(N_CARDS);
    for (int i = 0; i < N_CARDS; i++) tmp[i] = bestHand[i].first;    
    sort(tmp.begin(), tmp.end());
    for (int i = 1; i < N_CARDS; i++)
        if (tmp[i] - tmp[i - 1] != 1) ok = false;
    if (tmp == vector <int> {1, 10, 11, 12, 13}) ok = true;
    return (ok and not straightFlush());
}

bool threeOfAKind() {
    for (int i = 0, ct; i < N_CARDS; i++) {
        ct = 0;
        for (int j = 0; j < N_CARDS; j++)
            if (bestHand[i].first == bestHand[j].first) ct++;
        if (ct == 3 and not fullHouse()) return true;
    }
    return false;
}

bool twoPairs() {
    int val1 = -1, val2 = -1, val3 = -1;
    val1 = bestHand[0].first;
    for (int i = 1; i < N_CARDS; i++)
        if (bestHand[i].first != val1)
            val2 = bestHand[i].first;
    for (int i = 2; i < N_CARDS; i++)
        if (bestHand[i].first != val1 and bestHand[i].first != val2)
            val3 = bestHand[i].first;
    vector <int> ct(3, 0);
    for (int i = 0; i < N_CARDS; i++)
        if (bestHand[i].first == val1) ct[0]++;
        else if (bestHand[i].first == val2) ct[1]++;
        else if (bestHand[i].first == val3) ct[2]++;
    sort(ct.begin(), ct.end());
    return ct == vector <int> {1, 2, 2};
}

bool onePair() {
    vector <int> tmp(N_CARDS);
    for (int i = 0; i < N_CARDS; i++) tmp[i] = bestHand[i].first;
    return (set <int> (tmp.begin(), tmp.end())).size() == 4;
}

bool highestCard() {
    return true;
}

void getBestHand(int mask) {
    for (int i = 0, id = 0; i < N_CARDS; i++) {
        if ((mask >> i) & 1) bestHand[i] = hand[i];
        else bestHand[i] = deck[id++];
    }
}

void solve() {
    for (int mask = 0; mask < (1 << N_CARDS); mask++) {
        do {
            getBestHand(mask);
            if (highestCard()) ans = max(ans, 0);
            if (onePair()) ans = max(ans, 1);
            if (twoPairs()) ans = max(ans, 2);
            if (threeOfAKind()) ans = max(ans, 3);
            if (straight()) ans = max(ans, 4);
            if (flush()) ans = max(ans, 5);
            if (fullHouse()) ans = max(ans, 6);
            if (fourOfaKind()) ans = max(ans, 7);
            if (straightFlush()) ans = max(ans, 8);
        } while (next_permutation(hand.begin(), hand.end()));
    }
}

void init() {
    ans = -1;
}

pair <int, int> makeCard() {
    if (isdigit(card[0])) return {card[0] - '0', card[1]};
    if (card[0] == 'A') return {1, card[1]};
    if (card[0] == 'T') return {10, card[1]};
    if (card[0] == 'J') return {11, card[1]};
    if (card[0] == 'Q') return {12, card[1]};
    if (card[0] == 'K') return {13, card[1]};
}

bool read() {
    for (int i = 0; i < N_CARDS; i++) {
        if (scanf("%s", card) != 1) return false;
        if (i == 0) printf("Hand: ");
        hand[i] = makeCard();
        printf("%s ", card);
    }
    printf("Deck: ");
    for (int i = 0; i < N_CARDS; i++) {
        scanf("%s", card);
        deck[i] = makeCard();
        printf("%s ", card);
    }
    return true;
}

int main() {
    while(read()) {
        init();
        solve();
        print();
    }
    return (0);
}