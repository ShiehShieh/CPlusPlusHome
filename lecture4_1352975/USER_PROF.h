#ifndef USER_PROF
#define USER_PROF

#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> v;

class Player
{
	friend std::ostream& operator<<(std::ostream& os, Player& p);
public:
	Player(std::string str1 = "guest", std::string str2 = "unknow", std::vector<std::string> vstr1 = v, std::vector<std::string> vstr2 = v, float f1 = 0, std::string str3 = "beginner"):
	name(str1), login_time(str2), played_matches(vstr1), won_matches(vstr2), ratio(f1), rank(str3){}
	~Player(){}
	bool operator==(const Player &right)
	{
		return this->login_time == right.login_time && this->name == right.name && this->played_matches == right.played_matches && this->rank == right.rank && this->ratio == right.ratio && this->won_matches == right.won_matches;
	}
	bool operator!=(const Player &right)
	{
		return !(*this == right);
	}

private:
	std::string name;
	std::string login_time;
	std::vector<std::string> played_matches;
	std::vector<std::string> won_matches;
	float ratio;
	std::string rank;

};

class User_prof
{
	friend User_prof;
	friend std::ostream& operator<<(std::ostream& os, User_prof& u);
public:
	User_prof(){}
	~User_prof(){}
	void login(Player& p){
		vPlayer.push_back(p);
	}
	void logout(){
		vPlayer.pop_back();
	}
	int vsize(){
		return vPlayer.size();
	}
/*	bool operator==(const User_prof& u)
	{
		return this->vPlayer == u.vPlayer;
	}
	bool operator!=(const User_prof& u)
	{
		return !(*this == u);
	}
*/
private:
	std::vector<Player> vPlayer;
};

std::ostream& operator<<(std::ostream& os, Player& p){
	std::cout << p.name << " " << p.login_time << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, User_prof& u){
	for (std::vector<Player>::iterator i = u.vPlayer.begin(); i != u.vPlayer.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
	std::cout << std::endl;
	return os;
}

/*
class User_prof
{
public:
	User_prof(std::string str1 = "guest", std::string str2 = "unknow", std::vector<std::string> vstr1 = v, std::vector<std::string> vstr2 = v, float f1 = 0, std::string str3 = "beginner"):
	name(str1), login_time(str2), played_matches(vstr1), won_matches(vstr2), ratio(f1), rank(str3){}
	~User_prof();
	bool operator==(const User_prof &right)
	{
		return this->login_time == right.login_time && this->name == right.name && this->played_matches == right.played_matches && this->rank == right.rank && this->ratio == right.ratio && this->won_matches == right.won_matches;
	}
	bool operator!=(const User_prof &right)
	{
		return !(*this == right);
	}

private:
	std::string name;
	std::string login_time;
	std::vector<std::string> played_matches;
	std::vector<std::string> won_matches;
	float ratio;
	std::string rank;

};
*/

#endif