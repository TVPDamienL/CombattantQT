#include "combattant.h"


cWeapon::cWeapon( const std::string & iName, int iDamage ) :
    mName( iName ),
    mDamage( iDamage )
{
}


const std::string &
cWeapon::Name() const
{
    return  mName;
}


void
cWeapon::Name( const std::string & iName )
{
    mName = iName;
}


int
cWeapon::Damage() const
{
    return  mDamage;
}


void
cWeapon::Damage( int iDamage )
{
    mDamage = iDamage;
}


// =========================
// =========================
// =========================
// =========================


cCombattant::~cCombattant()
{
    delete  mWeapon0;
    delete  mWeapon1;
    delete  mWeapon2;
    delete  mWeapon3;
}


cCombattant::cCombattant() :
    mName( "" ),
    mCurrentWeapon( 0 ),
    mShieldRating( 0 )
{
    mWeapon0 = new cWeapon( "None", 66 );
    mWeapon1 = new cWeapon( "Dagger", 2 );
    mWeapon2 = new cWeapon( "Sword", 6 );
    mWeapon3 = new cWeapon( "Pike", 12 );
    mCurrentWeapon = mWeapon0;
}


const std::string&
cCombattant::Name() const
{
    return  mName;
}


void
cCombattant::Name( const std::string & iName )
{
    mName = iName;
}


int
cCombattant::ShieldRating() const
{
    return  mShieldRating;
}


void
cCombattant::ShieldRating( int iShieldRating )
{
    mShieldRating = iShieldRating;
}



int
cCombattant::WeaponCount() const
{
    return  4;
}


cWeapon*
cCombattant::WeaponAtIndex( int iIndex )
{
    switch( iIndex )
    {
        case 0:     return  mWeapon0;
        case 1:     return  mWeapon1;
        case 2:     return  mWeapon2;
        case 3:     return  mWeapon3;
        default:    return  0;
    }
}


cWeapon*
cCombattant::CurrentWeapon()
{
    return  mCurrentWeapon;
}


void
cCombattant::CurrentWeapon( int iIndex )
{
    mCurrentWeapon = WeaponAtIndex( iIndex );
}


void
cCombattant::CurrentWeapon( const std::string & iName )
{
    if( iName == mWeapon0->Name() )
        mCurrentWeapon = mWeapon0;
    else if( iName == mWeapon1->Name() )
        mCurrentWeapon = mWeapon1;
    else if( iName == mWeapon2->Name() )
        mCurrentWeapon = mWeapon2;
    else if( iName == mWeapon3->Name() )
        mCurrentWeapon = mWeapon3;
    else
        mCurrentWeapon = 0;
}


int
cCombattant::CurrentWeaponIndex() const
{
    if( mCurrentWeapon == mWeapon0 )
        return  0;
    else if( mCurrentWeapon == mWeapon1 )
        return  1;
    else if( mCurrentWeapon == mWeapon2 )
        return  2;
    else if( mCurrentWeapon == mWeapon3 )
        return  3;

    return  -1;
}
