#include "stdafx.h"
#include "fip.h"


void vectory(std::vector<std::vector<std::wstring> >& menu_items,
			 std::vector<std::vector<std::vector<std::wstring> > >& div,
			 std::vector<std::vector<std::vector<std::wstring> > >& pliki)
{
//tworzebnie vectora
	std::vector<std::wstring> temp;
	std::vector<std::vector<std::wstring> > zbiorowy;

	temp.push_back(L"FIP_Spot.mpg");
	temp.push_back(L"about-us.pdf");
	temp.push_back(L"Handbook_raccordi.pdf");
	temp.push_back(L"Handbook_valvole.pdf");
	menu_items.push_back(temp);
	temp.clear();
	temp.push_back(L"Brochure_VKD.pdf");
	temp.push_back(L"Brochure_TKD.pdf");
	temp.push_back(L"Brochure_MK-CP.pdf");
	temp.push_back(L"Brochure_VEE.pdf");
	temp.push_back(L"Brochure_VXE.pdf");
	temp.push_back(L"Brochure_labelling_system.pdf");
	temp.push_back(L"Brochure_FS_FC.pdf");
	menu_items.push_back(temp);
	temp.clear();	
/*
###########################
###		zbiorowy		###
###########################
*/
//menu zbiorowy[0][0]
	temp.push_back(L"FIP spot");
	temp.push_back(L"O FIP-ie");
	temp.push_back(L"Podrêcznik kszta³tek");
	temp.push_back(L"Podrêcznik zaworów");
	temp.push_back(L"Broszury");
	temp.push_back(L"Katalogi techniczne");
	temp.push_back(L"Kontakt");
	temp.push_back(L"Kemy");
	zbiorowy.push_back(temp);
//produkty menu zbiorowy [0][1]
	temp.clear();
	temp.push_back(L"Zawory z napêdami");
	temp.push_back(L"Zawory rêczne z PVC-U");
	temp.push_back(L"Kszta³tki PVC-U");
	temp.push_back(L"System PP-H");
	temp.push_back(L"System PVC-C TemperFIP100\xAE");
	temp.push_back(L"System PVDF");
	temp.push_back(L"System PE-HD");
	temp.push_back(L"System ABS");
	zbiorowy.push_back(temp);
//menu broszury [0][2]
	temp.clear();
	temp.push_back(L"VKD - Zawory kulowe DualBlock\xAE");
	temp.push_back(L"TKD - Zawory kulowe trójdrozne DualBlock\xAE");
	temp.push_back(L"MK/CP - Zawory membranowe pneumatyczne z napêdem t³okowym");
	temp.push_back(L"VEE - Zawory kulowe Easyfit\xAE");
	temp.push_back(L"VXE - Zawory kulowe Easyfit\xAE");
	temp.push_back(L"System etykiet do zaworów Easyfit\xAE");
	temp.push_back(L"FS-FC - Rotametry");
	zbiorowy.push_back(temp);
//#################################
//# system PE - zbiorowy [0][3] #
//#################################
	temp.clear();
	temp.push_back(L"Kszta³tki doczo³owe");
	temp.push_back(L"Z³¹czki elektrooporowe FRIALEN®");
	temp.push_back(L"Wytyczne dla projektantów");
	zbiorowy.push_back(temp);
//#################################
//# system ABS - zbiorowy [0][4] #
//#################################
	temp.clear();
	temp.push_back(L"Informacje ogólne");
	temp.push_back(L"System metryczny");
	temp.push_back(L"System calowy");
	temp.push_back(L"System preizolowany");
	temp.push_back(L"Klejenie");
	zbiorowy.push_back(temp);
	div.push_back(zbiorowy);
	zbiorowy.clear();
//################################
//# actuaded zawory zbiorowy [1] #
//################################
	temp.clear();
	temp.push_back(L"Si³owniki Elektryczne");
	temp.push_back(L"Si³owniki Pneumatyczne");
	temp.push_back(L"Zawory bezpieczeñstwa");
	temp.push_back(L"Rotametry");
	zbiorowy.push_back(temp);
//elektryczna coœtam zbiorowy
	temp.clear();
	temp.push_back(L"Zawory kulowe");
	temp.push_back(L"Przepustnice");
	temp.push_back(L"Elektrozawory");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//zawory kulowe
	temp.clear();
	temp.push_back(L"VKD/CE - Zawór kulowy Dual Block \xAE DN 10-50 z si³ownikiem elektrycznym");
	temp.push_back(L"VKD/CE - Zawór kulowy Dual Block \xAE DN 65-100 z si³ownikiem elektrycznym");
	temp.push_back(L"TKD/CE - Trójdro¿ny zawór kulowy Dual Block \xAE z si³ownikiem elektrycznym");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//zawory motylkowe
	temp.clear();
	temp.push_back(L"FE/CE");
	temp.push_back(L"FK/CE");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//zawory cewkowe
	temp.clear();
	temp.push_back(L"S1-S2");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//pneumatyczne costam zbiorowy
	temp.clear();
	temp.push_back(L"Zawory kulowe");
	temp.push_back(L"Przepustnice");
	temp.push_back(L"Zawory membranowe");
	temp.push_back(L"Zawory skoœne");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//kulowe
	temp.clear();
	temp.push_back(L"VKD/CE - Zawór kulowy Dual Block \xAE DN 10-50 z si³ownikiem pneumstycznym");
	temp.push_back(L"VKD/CE - Zawór kulowy Dual Block \xAE DN 65-100 z si³ownikiem pneumstycznym");
	temp.push_back(L"TKD/CE - Trójdro¿ny zawór kulowy Dual Block \xAE z si³ownikiem pneumstycznym");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//motylkowe
	temp.clear();
	temp.push_back(L"FE/CP");
	temp.push_back(L"FK/CP");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//diacoœtam
	temp.clear();
	temp.push_back(L"VM/CP-NC - Zawór membranowy pneumatyczny normalnie zamkniêty");
	temp.push_back(L"VM/CP-NO - Zawór membranowy pneumatyczny normalnie otwarty");
	temp.push_back(L"MK/CP-NC - Zawór membranowy pneumatyczny normalnie zamkniety z si³ownikiem t³okowym");
	temp.push_back(L"MK/CP-NO - Zawór membranowy pneumatyczny normalnie otwarty z si³ownikiem t³okowym");
	temp.push_back(L"MK/CP-DA - Zawór membranowy pneumatyczny obustronego dzia³ania z si³ownikiem t³okowym");
	temp.push_back(L"DM/CP-NO - Zawór membranowy pneumatyczny normalnie otwarty bezsprê¿ynowy");
	temp.push_back(L"CM/CP - Zawór membranowy pneumatyczny - kompaktowy");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//k¹towy 
	temp.clear();
	temp.push_back(L"VV/CP - zawory skoœne pneumatyczne");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//relief zbiorowy
	temp.clear();
	temp.push_back(L"SV - Zawór skoœny upustowy");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//przep³ywomierze zbiorowy
	temp.clear();
	temp.push_back(L"FS - rotametry standartowe");
	temp.push_back(L"FC - rotametry krótkie");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
	div.push_back(zbiorowy);
	zbiorowy.clear();
//#################################
//# manualne zawory zbiorowy [2] #
//#################################
	temp.clear();
	temp.push_back(L"Informacje ogólne");
	temp.push_back(L"Zawory kulowe");
	temp.push_back(L"Przepustnice");
	temp.push_back(L"Zawory membranowe");
	temp.push_back(L"Zawory zwrotne");
	temp.push_back(L"Filtry");
	temp.push_back(L"Pozosta³e zawory");
	zbiorowy.push_back(temp);
//kulowe
	temp.clear();
	temp.push_back(L"VKD PVC-U - Zawory kulowe Dual Block\xAE DN 10-50");
	temp.push_back(L"VKD PVC-U - Zawory kulowe Dual Block\xAE DN 65-100");
	temp.push_back(L"TKD PVC-U - Trójdro¿ne zawory kulowe Dual Block\xAE");
	temp.push_back(L"VEE PVC-U - Zawory kulowe serii Easyfit");
	temp.push_back(L"VE PVC-U - Zawory kulowe DN 65-100");
	temp.push_back(L"VXE PVC-U - Zawory kulowe serii Easyfit");
	temp.push_back(L"VX PVC-U - Zawory kulowe serii Ergo DN 65-100");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//przepustnice
	temp.clear();
	temp.push_back(L"FE PVC-U");
	temp.push_back(L"FK PVC-U");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//membranowe
	temp.clear();
	temp.push_back(L"VM PVC-U - Zawory membranowe");
	temp.push_back(L"VM/RM-PVC-U - Mini zawory membranowe");
	temp.push_back(L"CM PVC-U - Kompaktowe zawory membranowe");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//bezpieczeñstwa
	temp.clear();
	temp.push_back(L"VR PVC-U - Zawór zwrotny");
	temp.push_back(L"SR PVC-U - Kulowy zawór zwrotny");
	temp.push_back(L"CR PVC-U - Klapa zwrotna");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//Filtry
	temp.clear();
	temp.push_back(L"RV PVC-U - Filtry siatkowe");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//Pozosta³e
	temp.clear();
	temp.push_back(L"VA PVC-U - Zawory odpowietrzaj¹co napowietrzaj¹ce");
	temp.push_back(L"VZ PVC-U - Zawory stopowe");
	temp.push_back(L"VV PVC-U - Zawory skoœne");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
	div.push_back(zbiorowy);
	zbiorowy.clear();
//#################################
//# kszta³tki zbiorowy [3] #
//#################################
	temp.clear();
	temp.push_back(L"Informacje ogólne");
	temp.push_back(L"Instrukcja klejenia");
	temp.push_back(L"System metryczny");
	temp.push_back(L"System calowy");
	zbiorowy.push_back(temp);
//montaz pdf
	temp.clear();
	temp.push_back(L"");
	zbiorowy.push_back(temp);
//iso
	temp.clear();
	temp.push_back(L"Kszta³tki klejone");
	temp.push_back(L"Kszta³tki przejsciowe");
	temp.push_back(L"Kszta³tki gwintowe");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//BS
	temp.clear();
	temp.push_back(L"Kszta³tki klejone");
	temp.push_back(L"Kszta³tki przejsciowe");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
	div.push_back(zbiorowy);
	zbiorowy.clear();
//#################################
//# PP-H system - zbiorowy [4] #
//#################################
	temp.clear();
	temp.push_back(L"Informacje ogólne");
	temp.push_back(L"Instrukcje zgrzewania");
	temp.push_back(L"Rury i kszta³tki");
	temp.push_back(L"Zawory kulowe");
	temp.push_back(L"Przepustnice");
	temp.push_back(L"Zawory membranowe");
	temp.push_back(L"Zawory zwrotne");
	temp.push_back(L"Filtry");
	zbiorowy.push_back(temp);
//instrukcje
	temp.clear();
	temp.push_back(L"Zgrzewanie mufowe");
	temp.push_back(L"Zgrzewanie doczo³owe");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//rury
	temp.clear();
	temp.push_back(L"Rury");
	temp.push_back(L"Kszta³tki do zgrzewania mufowego");
	temp.push_back(L"Kszta³tki do zgrzewania doczo³owego");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//kulowe
	temp.clear();
	temp.push_back(L"VKD PP-H - Zawory kulowe Dual Block\xAE DN 10-50");
	temp.push_back(L"VKD PP-H - Zawory kulowe Dual Block\xAE DN 65-100");
	temp.push_back(L"TKD PP-H - Trójdro¿ne zawory kulowe Dual Block\xAE");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//przepustnice
	temp.clear();
	temp.push_back(L"FK PP-H");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//membr
	temp.clear();
	temp.push_back(L"VM PP-H - Zawory membranowe");
	temp.push_back(L"CM PP-H - Kompaktowe zawory membranowe");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//bezp
	temp.clear();
	temp.push_back(L"VR PP-H - Zawór bezpieczeñstwa");
	temp.push_back(L"SR PP-H - Kulowy zawór bezpieczeñstwa");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//filtr
	temp.clear();
	temp.push_back(L"RV PP-H - Filtr siatkowy");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
	div.push_back(zbiorowy);
	zbiorowy.clear();
//#################################
//# temperfip - zbiorowy - [5] #
//#################################
	temp.clear();
	temp.push_back(L"Informacje ogólne");
	temp.push_back(L"Instrukcje klejenia");
	temp.push_back(L"Rury i kszta³tki");
	temp.push_back(L"Zawory kulowe");
	temp.push_back(L"Przepustnice");
	temp.push_back(L"Zawory membranowe");
	temp.push_back(L"Zawory zwrotne");
	temp.push_back(L"Filtry");
	zbiorowy.push_back(temp);
//klejenie
	temp.clear();
	temp.push_back(L"");
	zbiorowy.push_back(temp);
//rury
	temp.clear();
	temp.push_back(L"Rury");
	temp.push_back(L"Kszta³tki do klejenia");
	temp.push_back(L"Kszta³tki przejœciowe");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//kulowe
	temp.clear();
	temp.push_back(L"VKD PVC-C - Zawory kulowe Dual Block\xAE DN 10-50");
	temp.push_back(L"VKD PVC-C - Zawory kulowe Dual Block\xAE DN 65-100");
	temp.push_back(L"TKD PVC-C - Trójdro¿ne zawory kulowe Dual Block\xAE");
	temp.push_back(L"VXE PVC-C - Zawory kulowe serii Easyfit");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//przepustnice
	temp.clear();
	temp.push_back(L"FK PVC-C");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//membranowe
	temp.clear();
	temp.push_back(L"VM PVC-C - Zawory membranowe");
	temp.push_back(L"CM PVC-C - Kompaktowe zawory membranowe");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//bezp
	temp.clear();
	temp.push_back(L"SR PVC-C - Kulowy zawór zwrotny");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//filtr
	temp.clear();
	temp.push_back(L"RV PVC-C - Filtr siatkowy");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
	div.push_back(zbiorowy);
	zbiorowy.clear();
//#################################
//# PVDF system - zbiorowy [6] #
//#################################
	temp.clear();
	temp.push_back(L"Informacje ogólne");
	temp.push_back(L"Instrukcja zgrzewania");
	temp.push_back(L"Rury i kszta³tki");
	temp.push_back(L"Zawory kulowe");
	temp.push_back(L"Przepustnice");
	temp.push_back(L"Zawory membranowe");
	temp.push_back(L"Zawory zwrotne");
	zbiorowy.push_back(temp);
//instrukcje - pdf
	temp.clear();
	temp.push_back(L"");
	zbiorowy.push_back(temp);
//rury 
	temp.clear();
	temp.push_back(L"Rury");
	temp.push_back(L"Kszta³tki do zgrzewania mufowego");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//kulowe
	temp.clear();
	temp.push_back(L"VKD PVDF - Zawory kulowe Dual Block\xAE DN 10-50");
	temp.push_back(L"VKD PVDF - Zawory kulowe Dual Block\xAE DN 65-100");
	temp.push_back(L"TKD PVDF - Trójdro¿ne zawory kulowe Dual Block\xAE");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//przepustnice
	temp.clear();
	temp.push_back(L"FK PVDF");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//membr
	temp.clear();
	temp.push_back(L"VM PVDF - Zawory membranowe");
	temp.push_back(L"CM PVDF - Kompaktowe zawory membranowe");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
//bezp
	temp.clear();
	temp.push_back(L"SR PVDF - Kulowy zawór zwrotny");
	temp.push_back(L"Powrót");
	zbiorowy.push_back(temp);
	div.push_back(zbiorowy);
	zbiorowy.clear();
/*
###########################
###	pliki	zbiorowy	###
###########################
*/
	temp.clear();
	temp.push_back(L"VKD_CE_10-50.pdf");//[0][0][0]
	temp.push_back(L"VKD_CE_65-100.pdf");
	temp.push_back(L"TKD_CE.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"FE_CE.pdf");
	temp.push_back(L"FK_CE.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"S1_S2.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	pliki.push_back(zbiorowy);
	zbiorowy.clear();
	temp.push_back(L"VKD_CP_10-50.pdf");//[1][0][0]
	temp.push_back(L"VKD_CP_65-100.pdf");
	temp.push_back(L"TKD_CP.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"FE_CP.pdf");
	temp.push_back(L"FK_CP.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VM_CP_NC.pdf");
	temp.push_back(L"VM_CP_NO.pdf");
	temp.push_back(L"MK_CP.pdf");
	temp.push_back(L"MK_CP.pdf");
	temp.push_back(L"MK_CP.pdf");
	temp.push_back(L"DM_CP_NO.pdf");
	temp.push_back(L"CM_CP.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VV_CP.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	pliki.push_back(zbiorowy);
	zbiorowy.clear();
	temp.push_back(L"SV.pdf");//[2][0][0]
	zbiorowy.push_back(temp);
	temp.clear();
	pliki.push_back(zbiorowy);
	zbiorowy.clear();
	temp.push_back(L"FS.pdf");//[3][0][0]
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"FC.pdf");//[3][1][0]
	zbiorowy.push_back(temp);
	temp.clear();
	pliki.push_back(zbiorowy);
	zbiorowy.clear();
//p12
	temp.push_back(L"PVC-U_VALVES_general_info.pdf");//[4][0][0]
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VKD_PVC-U_10-50.pdf");
	temp.push_back(L"VKD_PVC-U_65-100.pdf");
	temp.push_back(L"TKD_PVC-U.pdf");
	temp.push_back(L"VEE_PVC-U.pdf");
	temp.push_back(L"VE_PVC-U_65-100.pdf");
	temp.push_back(L"VXE_PVC-U.pdf");
	temp.push_back(L"VX_PVC-U_65-100.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"FE_PVC-U.pdf");
	temp.push_back(L"FK_PVC-U.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VM_PVC-U.pdf");
	temp.push_back(L"VM-RM_PVC-U.pdf");
	temp.push_back(L"CM_PVC-U.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VR_PVC-U.pdf");
	temp.push_back(L"SR_PVC-U.pdf");
	temp.push_back(L"CR_PVC-U.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"RV_PVC-U.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VA_PVC-U.pdf");
	temp.push_back(L"VZ_PVC-U.pdf");
	temp.push_back(L"VV_PVC-U.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	pliki.push_back(zbiorowy);
	zbiorowy.clear();
//p13
	temp.push_back(L"PVC-U_FITTINGS_general_info.pdf");//[5][0][0]
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"PVC-U_cementing_instructions.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"PVC-U_ISO-UNI.pdf");
	temp.push_back(L"PVC-U_ISO-BSP.pdf");
	temp.push_back(L"PVC-U_BSP.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"PVC-U_BS.pdf");
	temp.push_back(L"PVC-U_BS.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	pliki.push_back(zbiorowy);
	zbiorowy.clear();
//p14
	temp.push_back(L"PP-H_general_info.pdf");//[6][0][0]
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"PP-H_SW_instructions.pdf");
	temp.push_back(L"PP-H_BW_instructions.pdf");			
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"PP-H_PIPES.pdf");
	temp.push_back(L"PP-H_ISO-UNI_SW.pdf");
	temp.push_back(L"PP-H_ISO-UNI_BW.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VKD_PP-H_10-50.pdf");
	temp.push_back(L"VKD_PP-H_65-100.pdf");
	temp.push_back(L"TKD_PP-H.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"FK_PP-H.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VM_PP-H.pdf");
	temp.push_back(L"CM_PP-H.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VR_PP-H.pdf");
	temp.push_back(L"SR_PP-H.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"RV_PP-H.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	pliki.push_back(zbiorowy);
	zbiorowy.clear();
//p15
	temp.push_back(L"PVC-C_general_info.pdf");//[7][0][0]
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"PVC-C_cementing_instructions.pdf");//[7][1][0]
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"PVC-C_PIPES.pdf");//[7][2][0]
	temp.push_back(L"PVC-C_ISO-UNI-BSP.pdf");
	temp.push_back(L"PVC-C_ISO-UNI-BSP.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VKD_PVC-C_10-50.pdf");
	temp.push_back(L"VKD_PVC-C_65-100.pdf");
	temp.push_back(L"TKD_PVC-C.pdf");
	temp.push_back(L"VXE_PVC-C.pdf");
	temp.push_back(L"VX_PVC-C_65-100");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"FK_PVC-C.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VM_PVC-C.pdf");
	temp.push_back(L"CM_PVC-C.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"SR_PVC-C.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"RV_PVC-C.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	pliki.push_back(zbiorowy);
	zbiorowy.clear();
//p16
	temp.push_back(L"PVDF_general_info.pdf");//[8][0][0]
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"PVDF_SW_instructions.pdf");//[8][1][0]
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"PVDF_PIPES.pdf");//820
	temp.push_back(L"PVDF_ISO-UNI_SW.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VKD_PVDF_10-50.pdf");//830
	temp.push_back(L"VKD_PVDF_65-100.pdf");
	temp.push_back(L"TK_PVDF.pdf");//832
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"FK_PVDF.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"VM_PVDF.pdf");
	temp.push_back(L"CM_PVDF.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	temp.push_back(L"SR_PVDF.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	pliki.push_back(zbiorowy);
	zbiorowy.clear();
//p17
	temp.push_back(L"Akatherm_PE100.pdf");//[9][0][0]
	temp.push_back(L"FRIALEN.pdf");
	temp.push_back(L"Akatherm_Projektanci.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	pliki.push_back(zbiorowy);
	zbiorowy.clear();
//p18
	temp.push_back(L"ABS_ogolnie.pdf");//[10][0][0]
	temp.push_back(L"ABS_metryczny.pdf");
	temp.push_back(L"ABS_calowy.pdf");
	temp.push_back(L"ABS_preizolowany.pdf");
	temp.push_back(L"ABS_klejenie.pdf");
	zbiorowy.push_back(temp);
	temp.clear();
	pliki.push_back(zbiorowy);
	zbiorowy.clear();
}