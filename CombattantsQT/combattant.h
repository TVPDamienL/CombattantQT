#pragma once

#include <string>

class cWeapon
{
public:
    cWeapon( const std::string& iName, int iDamage );

    const std::string&  Name() const;
    void                Name( const std::string& iName );

    int                 Damage() const;
    void                Damage( int iDamage );

private:
    std::string     mName;
    int             mDamage;

};

// ===================
// ===================
// ===================

class cCombattant
{
public:
    ~cCombattant();
    cCombattant();

public:
    const std::string&  Name() const;
    void                Name( const std::string& iName );

    int                 ShieldRating() const;
    void                ShieldRating( int iShieldRating );

    int                 WeaponCount() const;
    cWeapon*            WeaponAtIndex( int iIndex );
    cWeapon*            CurrentWeapon();
    void                CurrentWeapon( int iIndex );
    int                 CurrentWeaponIndex() const;

private:
    std::string     mName;
    cWeapon*        mWeapon1;
    cWeapon*        mWeapon2;
    cWeapon*        mWeapon3;
    cWeapon*        mCurrentWeapon;
    int             mShieldRating;
};

