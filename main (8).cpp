

#include <bits/stdc++.h>
using namespace std;

char board[3][3];

void init_board() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

void print_board() {
    cout << "  1   2   3\n";
    for (int i = 0; i < 3; ++i) {
        cout << i+1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "  ---------\n";
    }
}

bool is_winner(char p) {
    // satırlar ve sütunlar
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == p && board[i][1] == p && board[i][2] == p) return true;
        if (board[0][i] == p && board[1][i] == p && board[2][i] == p) return true;
    }
    // çaprazlar
    if (board[0][0] == p && board[1][1] == p && board[2][2] == p) return true;
    if (board[0][2] == p && board[1][1] == p && board[2][0] == p) return true;
    return false;
}

bool board_full() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ') return false;
    return true;
}

pair<int,int> read_move(char player) {
    while (true) {
        cout << "Oyuncu " << player << " için hamle gir (satır sütun, örn: 2 3): ";
        int r, c;
        if (!(cin >> r >> c)) {
            cin.clear();
            string trash;
            getline(cin, trash);
            cout << "Geçersiz giriş. Tekrar deneyin.\n";
            continue;
        }
        if (r < 1 || r > 3 || c < 1 || c > 3) {
            cout << "Satır ve sütun 1 ile 3 arasında olmalı.\n";
            continue;
        }
        if (board[r-1][c-1] != ' ') {
            cout << "O hücre dolu. Başka hücre seçin.\n";
            continue;
        }
        return {r-1, c-1};
    }
}

int main() {
    cout << "XOX (Tic-Tac-Toe) oyunu. 2 oyuncu, sırayla hamle yapar.\n";
    while (true) {
        init_board();
        char current = 'X';
        while (true) {
            print_board();
            auto [r, c] = read_move(current);
            board[r][c] = current;
            if (is_winner(current)) {
                print_board();
                cout << "Tebrikler! Oyuncu " << current << " kazandı!\n";
                break;
            }
            if (board_full()) {
                print_board();
                cout << "Oyun berabere!\n";
                break;
            }
            current = (current == 'X') ? 'O' : 'X';
        }
        cout << "Tekrar oynamak ister misiniz? (e/h): ";
        char ch;
        cin >> ch;
        if (ch == 'e' || ch == 'E') {
            continue;
        } else {
            cout << "Çıkılıyor. Görüşürüz!\n";
            break;
        }
    }
    return 0;
}