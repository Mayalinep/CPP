#ifndef HUMANB_HPP
# define HUMANB_HPP


#include "Weapon.hpp"


class HumanB{
    private:
    std::string name;
    Weapon* weapon;

    public:
    HumanB(std::string name);
    void attack();
	void setWeapon(Weapon& weapon);
	~HumanB();
};

#endif