/*
 ____________________________________________
| CWaypointRegion.h - definicja klasy.       |
| SCI - by Jack Flower February 2012.        |
|____________________________________________|

*/


#ifndef _H_WAY_POINT_REGION
#define _H_WAY_POINT_REGION

#include "CWaypoint.h"
#include "../CDynamicRegion.h"

///
///Forward declaration
///
class CDynamicRegion;

///
///Klasa reprezentuje obszar na mapie
///
class CWaypointRegion : public CWaypoint
{
public:
	///
	///Konstruktor (wyra�ny - explicit)
	///
	///@param *region - wska�nik na obiekt klasy CDynamicRegion
	///
	explicit CWaypointRegion(CDynamicRegion * region);

	///
	///Konstruktor kopiuj�cy
	///
	///@param &other - sta�a referencja na obiekt klasy CWaypointRegion
	///
	CWaypointRegion(const CWaypointRegion & other);
	
	///
	///Destruktor wirtualny 
	///
	virtual ~CWaypointRegion();

	///
	///Wirtualna metoda zwraca unikalny identyfikator tego waypointa (node)
	///
    virtual int GetHash() const;

	///
	///Wirtualna metoda zwraca z wektora waypoint (node) s�siaduj�cy
	///
    virtual std::vector< CWaypoint * > GetNeighbours() const;

	///
	///Wirtualna metoda zwraca z wektora wska�nik clon waypointa (node)
	///
    virtual CWaypoint * Clone() const;
    
	///
	///Metoda zwraca wska�nik na obiekt klasy CDynamicRegion
	///
    CDynamicRegion * GetRegion() const    { return m_region; }
        
private:

    CDynamicRegion * m_region;	//obszar - region na mapie
};
#endif //_H_WAY_POINT_REGION
