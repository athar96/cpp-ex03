#include "Member.h"

using namespace std;

int Member::users = 0;


//constructor
Member::Member(){

	users++;
}

//destructor
Member::~Member(){
	users--;

	set<Member*>::iterator it;

	for ( it= following.begin() ; it != following.end(); it++ )
	{
		(*it)->followers.erase(this);
	}

	for ( it= followers.begin() ; it != followers.end(); it++ )
	{
		(*it)->following.erase(this);
	}
}
int Member::count(){
	return users;
}

int Member::numFollowers() const{
	int s= followers.size();
	return s;
}

int Member::numFollowing() const{
	int s = following.size();
	return s;
}

void Member::add(Member& member){
	followers.insert(&member);
}

void Member::removes(Member& member){
	followers.erase(&member);
}

void Member::follow(Member& member){

	if(&member == this)
		return;

	if(following.find(&member) == following.end()) {
		following.insert(&member);
		member.add(*this);
	}
}

void Member::unfollow(Member& member){

	if(&member == this)
		return;

	if (following.find(&member) != following.end())
	{
		following.erase(&member);
		member.removes(*this);
	}
}










