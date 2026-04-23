#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std;
using Pii = pair<int, int>;
int N, M, k;
bool bGameOver = false;

int Dx[4] = { 0, 0, -1, 1 };
int Dy[4] = { -1, 1, 0, 0 };

enum EDirection
{
	Up,
	Down,
	Left,
	Right
};


struct Player
{
	int Attack = 5;
	int Range = 1;
	int Speed = 1;
	int NeedExp = 10;
	int Exp = 0;
	int Level = 1;
	int Pills = 0;
	int MoveCost = 0;
	bool OVERDOSE = false;
};
struct Monster
{
	int Health;
	int Armor;
	int ExpDrop;
};

bool IsInGame(int Row, int Col)
{
	return (Row >= 0 && Col >= 0 && Row < N && Col < M);
}

void Teleport(vector<vector<char>>& Game, Player& P, int& Row, int& Col, EDirection Dir)
{
	int NewRow = Row + Dy[Dir] * P.Speed;
	int NewCol = Col + Dx[Dir] * P.Speed;
	if (IsInGame(NewRow, NewCol) && Game[NewRow][NewCol] != '*' && Game[NewRow][NewCol] != 'm')
	{
		P.MoveCost++;
		Row = NewRow;
		Col = NewCol;
	}
}

void DoNothing(Player& P)
{
	P.MoveCost++;
}

void Attack(vector<vector<char>>& Game, Player& P, map<Pii, Monster>& Monsters,int Row, int Col, EDirection Dir)
{
	for (int moving = 1; moving <= P.Range; moving++)
	{
		int NewRow = Row + Dy[Dir] * moving;
		int NewCol = Col + Dx[Dir] * moving;
		if (Game[NewRow][NewCol] == '*')
		{
			break;
		}
		if (Game[NewRow][NewCol] == 'm')
		{
			Monster& M = Monsters[{NewRow, NewCol}];
			if (P.Attack > M.Armor)
			{
				M.Health -= P.Attack - M.Armor;
			}
			if (M.Health <= 0)
			{
				Game[NewRow][NewCol] = '.';
				P.Exp += M.ExpDrop;
				Monsters.erase({ NewRow, NewCol });
			}
		}
	}
	P.MoveCost += 3;
}

void LevelUp(Player& P)
{
	P.Exp -= P.NeedExp;
	P.Attack += P.Level;
	P.Range++;
	P.NeedExp += 10;
	P.Level++;
}

void EatPill(Player& P, bool bIsUp)
{
	if (bIsUp)
	{
		P.Speed++;
	}
	else
	{
		if (P.Speed > 0)
		{
			P.Speed--;
		}
	}
	P.Pills++;
	P.MoveCost += 2;
}
void Clear(vector<vector<char>>& Game, int Row, int Col)
{
	if (Game[Row][Col] == 'g')
	{
		bGameOver = true;
	}
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	vector<vector<char>> Game(N, vector<char>(M));
	map<Pii, Monster> Monsters;
	Player Player;
	int Row, Col;

	for (int i = 0; i < N; i++)
	{
		string line;
		cin >> line;
		for (int j = 0; j < M; j++)
		{
			Game[i][j] = line[j];
			if (line[j] == 'p')
			{
				Row = i;
				Col = j;
				Game[i][j] = '.';
			}
			if (line[j] == 'm')
			{
				Monsters[{i, j}];
			}
		}
	}
	cin >> k; // 쓸모 업는디?
	for (auto iter = Monsters.begin(); iter != Monsters.end(); iter++)
	{
		int mh;
		cin >> mh;
		iter->second.Health = mh;
	}
	for (auto iter = Monsters.begin(); iter != Monsters.end(); iter++)
	{
		int md;
		cin >> md;
		iter->second.Armor = md;
	}
	for (auto iter = Monsters.begin(); iter != Monsters.end(); iter++)
	{
		int mexp;
		cin >> mexp;
		iter->second.ExpDrop = mexp;
	}
	int s;
	cin >> s;
	// 게임 시작
	// 임시값임
	int NeedToRelax = Player.MoveCost + 10;
	for(int i = 0; i < s; i++)
	{
		string Command;
		cin >> Command;
		if (bGameOver)
		{
			// Nothing
		}
		else if (Player.OVERDOSE)
		{
			if (Command == "u")
			{
				Teleport(Game, Player, Row, Col, Up);
			}
			else if (Command == "d")
			{
				Teleport(Game, Player, Row, Col, Down);
			}
			else if (Command == "l")
			{
				Teleport(Game, Player, Row, Col, Left);
			}
			else if (Command == "r")
			{
				Teleport(Game, Player, Row, Col, Right);
			}
			else if(Command == "w")
			{
				DoNothing(Player);
			}
			if (Player.MoveCost >= NeedToRelax)
			{
				Player.Pills = 0;
				Player.OVERDOSE = false;
			}
		}
		else
		{
			if (Command == "u")
			{
				Teleport(Game, Player, Row, Col, Up);
			}
			else if (Command == "d")
			{
				Teleport(Game, Player, Row, Col, Down);
			}
			else if(Command == "l")
			{
				Teleport(Game, Player, Row, Col, Left);
			}
			else if(Command == "r")
			{
				Teleport(Game, Player, Row, Col, Right);
			}
			else if(Command == "w")
			{
				DoNothing(Player);
			}
			else if(Command == "au")
			{
				Attack(Game, Player, Monsters, Row, Col, Up);
			}
			else if(Command == "ad")
			{
				Attack(Game, Player, Monsters, Row, Col, Down);
			}
			else if(Command == "al")
			{
				Attack(Game, Player, Monsters, Row, Col, Left);
			}
			else if(Command == "ar")
			{
				Attack(Game, Player, Monsters, Row, Col, Right);
			}
			else if(Command == "du")
			{
				EatPill(Player, true);
			}
			else if(Command == "dd")
			{
				EatPill(Player, false);
			}
			else if (Command == "c")
			{
				Clear(Game, Row, Col);
			}
			if (Player.Pills == 5 && !Player.OVERDOSE)
			{
				Player.OVERDOSE = true;
				NeedToRelax = Player.MoveCost + 10;
			}
			while (Player.Exp >= Player.NeedExp)
			{
				LevelUp(Player);
			}
		}
	}
	cout << Player.Level << ' ' << Player.Exp << '\n';
	cout << Player.MoveCost << '\n';
	Game[Row][Col] = 'p';
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << Game[i][j];
		}
		cout << '\n';
	}
	for (auto iter = Monsters.begin(); iter != Monsters.end(); iter++)
	{
		cout << iter->second.Health << ' ';
	}
	return 0;
}