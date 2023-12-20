#include <bits/stdc++.h>
using namespace std;

void displayboard(char board[9]) {
    cout<<"     |     |     \n";
    cout<<"   "<<board[0]<<" | "<<board[1]<<"   |  "<<board[2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"   "<<board[3]<<" | "<<board[4]<<"   |  "<<board[5]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"   "<<board[6]<<" | "<<board[7]<<"   |  "<<board[8]<<" \n";
    cout<<"     |     |     \n";
}

bool wincheck(char board[9]){
	if(board[0]==board[1] && board[1]==board[2]){
		return true;
	}
	else if(board[3]==board[4] && board[4]==board[5]){
		return true;
	}
	else if(board[6]==board[7] && board[7]==board[8]){
		return true;
	}
	//		end of rows check
	else if(board[0]==board[3] && board[3]==board[6]){
		return true;
	}
	else if(board[1]==board[4] && board[4]==board[7]){
		return true;
	}
	else if(board[2]==board[5] && board[5]==board[8]){
		return true;
	}
	// 		end of column check
	else if(board[0]==board[4] && board[4]==board[8]){
		return true;
	}
	else if(board[2]==board[4] && board[4]==board[6]){
		return true;
	}
	else {
		return false;
	}
	//		end of diagonal check
}

bool drawcheck(char board[9]){
	if (!wincheck(board)) {
        for (int i = 0; i < 9; i++) {
            if (board[i] != 'X' && board[i] != 'O') {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool computer_rowmoves(char board[9]){
	if (board[4]!='X'&& board[4]!='O'){
		board[4]='O';
		return true;
	}
	else if(board[0]==board[1] && board[2]=='3' ){
		board[3]='O';
		return true;
	} 
	else if (board[1]==board[2] && board[0]=='1'){
		board[0]='O';
		return true;
	}
	else if(board[3]==board[4] && board[5]=='6'){
		board[5]='O';
		return true;
	}
	else if (board[4]==board[5] && board[3]=='4'){
		board[3]='O';
		return true;
	}
	else if(board[6]==board[7] && board[8]=='9'){
		board[8]='O';
		return true;
	} 
	else if (board[7]==board[8] && board[6]=='7'){
		board[6]='O';
		return true;
	}
	else if (board[0]==board[2] && board[1]=='2'){
		board[1]='O';
		return true;
	}
	else if(board[3]==board[5] && board[4]=='5'){
		board[4]='O';
		return true;
	} 
	else if (board[6]==board[8] && board[7]=='8'){
		board[7]='O';
		return true;
	}
	else {
		return false;
	}
	//		end of rows check
	
	
}

bool computer_columnmoves(char board[9]){
	if (board[4]!='X'&& board[4]!='O'){
		board[4]='O';
		return true;
	}
	else if(board[0]==board[3] && board[6]=='7' ){
		board[6]='O';
		return true;
	} 
	else if (board[3]==board[6] && board[0]=='1'){
		board[0]='O';
		return true;
	}	// end of column 1
	else if(board[1]==board[4] && board[7]=='8'){
		board[7]='O';
		return true;
	}
	else if (board[4]==board[7] && board[1]=='2'){
		board[1]='O';
		return true;
	}	// end of column 2
	else if(board[2]==board[5] && board[8]=='9'){
		board[8]='O';
		return true;
	} 
	else if (board[5]==board[8] && board[2]=='3'){
		board[2]='O';
		return true;
	}	// end of column 3
	else if (board[0]==board[6] && board[3]=='4'){
		board[3]='O';
		return true;
	}
	else if(board[1]==board[7] && board[4]=='5'){
		board[4]='O';
		return true;
	} 
	else if (board[2]==board[8] && board[5]=='6'){
		board[5]='O';
		return true;
	}
	else{
		return false;
	}
}

bool computer_diagonalmoves(char board[9]){
	if(board[0]==board[4] && board[8]=='9' ){
		board[8]='O';
		return true;
	} 
	else if (board[0]==board[8] && board[4]=='5'){
		board[4]='O';
		return true;
	}	// end of column 1
	else if(board[4]==board[8] && board[0]=='1'){
		board[0]='O';
		return true;
	}
	else if (board[2]==board[4] && board[6]=='7'){
		board[6]='O';
		return true;
	}	// end of column 2
	else if(board[4]==board[6] && board[2]=='3'){
		board[2]='O';
		return true;
	} 
	else if (board[2]==board[6] && board[4]=='5'){
		board[4]='O';
		return true;
	}
	else{
		return false;
	}
}

bool random_move(char board[9]){
	 while (true) {
        int random = rand() % 9;
        if (board[random] == '1' + random) {
            board[random] = 'O';
            return true;
        }
    }
}

int main(){
	srand(time(0));
	char board[9]={'1','2','3','4','5','6','7','8','9'};
	bool valid;
	char move;
	while(!wincheck(board) && !drawcheck(board)){
		cout<<"Your turn, enter the square number which you want to mark.\n";
		displayboard(board);
		cin>>move;
		valid=false;
		while (valid==false){
			switch(move){
				case '1': if(board[0]=='1'){
						board[0]='X';
						valid =true;
						break;
						}
						else{
							valid=false;
							cin>>move;
						}
				break;
				case '2': if(board[1]=='2'){
						board[1]='X';
						valid =true;
						break;
						}
						else{
							valid=false;
							cin>>move;
						}
				break;
				case '3': if(board[2]=='3'){
						board[2]='X';
						valid =true;
						break;
						}
						else{
							valid=false;
							cin>>move;
						}
				break;
				case '4': if(board[3]=='4'){
						board[3]='X';
						valid =true;
						break;
						}
						else{
							valid=false;
							cin>>move;
						}
				break;
				case '5': if(board[4]=='5'){
						board[4]='X';
						valid =true;
						break;
						}
						else{
							valid=false;
							cin>>move;
						}
				break;
				case '6': if(board[5]=='6'){
						board[5]='X';
						valid =true;
						break;
						}
						else{
							valid=false;
							cin>>move;
						}
				break;
				case '7': if(board[6]=='7'){
						board[6]='X';
						valid =true;
						break;
						}
						else{
							valid=false;
							cin>>move;
						}
				break;
				case '8': if(board[7]=='8'){
						board[7]='X';
						valid =true;
						break;
						}
						else{
							valid=false;
							cin>>move;
						}
				break;
				case '9': if(board[8]=='9'){
						board[8]='X';
						valid =true;
						break;
						}
						else{
							valid=false;
							cin>>move;
						}
				break;
				default: cout<<"Invalid move, enter again.\n";
						cin>>move;
				break;
			}
		}
		valid=true;
		if(wincheck(board)){
			displayboard(board);
			cout<<"CONGRATULATIONS, YOU JUST BEAT MY PROGRAM WHICH I WOKRED ON FOR DAYS.";
			break;
		}
		if (drawcheck(board)){
			cout<<"The game was a draw.\n";
			break;
		}
		if (!computer_rowmoves(board)) {
	        if (!computer_columnmoves(board)) {
	            if(!computer_diagonalmoves(board)){
	            		random_move(board);
					}
				}
	        }
	    
		if(wincheck(board)){
			displayboard(board);
			cout<<"The AI won, better luck next time.\n";
			break;
		}
	}
}
