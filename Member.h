

//#define MEMBER_HPP_

#include <set>

class Member{
	static int users;

	std::set<Member*> followers;
	std::set<Member*> following;

	void add(Member&);

	void removes(Member&);


public:



	 Member();

	~Member();

	void follow(Member&);

	void unfollow(Member&);

	int numFollowers() const;

	int numFollowing() const;

	static int count();
};