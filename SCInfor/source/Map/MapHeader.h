//  __________________________________________________
// | MapHeader.h - definicja struktury opisujące mapę |
// | Jack Flower April 2013                           |
// |__________________________________________________|
//

#ifndef H_MAP_HEADER_JACK
#define H_MAP_HEADER_JACK

///
///Struktura opisuje konfigurację mapy
///
struct MapHeader
{
	int m_map_version; //wersja mapy
	int m_map_width_in_tile; //szerkość mapy w kaflach
	int m_map_height_in_tile; //wysokość mapy w kaflach
};
#endif //H_MAP_HEADER_JACK
