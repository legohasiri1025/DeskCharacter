#include "DxLib.h"
#include "LoadCfg.h"
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/optional.hpp>

using namespace boost::property_tree;
using namespace boost;
using namespace std;

#define MODE_PICTURE	(0)
#define MODE_VALUE	(1)
#define MODE_ELSE		(2)

void message_box(int mode) {
	int flag;
	char* mes = "";
	switch (mode) {
	case MODE_PICTURE:
		mes = "画像の読み込みに失敗しました。\n既定の値を読み込みますか?";
		break;
	case MODE_VALUE:
		mes = "数値の読み込みに失敗しました。\n既定の値を読み込みますか?";
		break;
	default:
		mes = "ファイルの読み込みに失敗しました。\n既定の値を読み込みますか?";
		break;
	}
	flag = MessageBox(NULL, TEXT(mes), TEXT("エラー"), MB_OKCANCEL | MB_ICONWARNING);
	if (flag == IDCANCEL) {
		DxLib_End();
		exit(-1);
	}
}


/*const char* IniLoadString(string filepass, string section,string key,string defaultstring) {//filepass is .ini file's pass   sectionkey format is Section.Key
	ptree pt;
	string sectionkey = section + "." + key;
	//printfDx(sectionkey.c_str());
	try {
		read_ini(filepass, pt);
		optional<string> value = pt.get_optional<string>(sectionkey);
		string s = value.get();
		return pt.get<char*>(sectionkey);
	}
	catch (ptree_error& e) {
		message_box(MODE_PICTURE);
	}
}*/

template <typename Type>Type IniLoadValue(string filepass, string section, string key,Type defaultvalue) {
	ptree pt;
	string sectionkey = section + "." + key;
	//printfDx(sectionkey.c_str());
	try {
		read_ini(filepass, pt);
		optional<Type> value = pt.get_optional<Type>(sectionkey);
		return  pt.get<Type>(sectionkey);
	}
	catch (ptree_error) {
		message_box(MODE_ELSE);
		return defaultvalue;
	}
}

const string INI = "../config.ini";
const string MS = "Message";
const string MN = "Month";
//会話画像
//キャラ、枠画像
const char* chara = IniLoadValue(INI, "Graphic", "Character", "../pictures/yuyuko.png");
//const char* chara = IniLoadString(INI, "Graphic", "Character");
const char* mswindow = IniLoadValue(INI, "Graphic", "MessageWindow", "../pictures/message_window1.png");

const char* string1 = IniLoadValue(INI, MS, "M1", "../pictures/string1.png");
const char* string2 = IniLoadValue(INI, MS, "M1", "../pictures/string2.png");
const char* string3 = IniLoadValue(INI, MS, "M1", "../pictures/string3.png");
const char* string4 = IniLoadValue(INI, MS, "M1", "../pictures/string4.png");
const char* string5 = IniLoadValue(INI, MS, "M1", "../pictures/string5.png");
const char* string6 = IniLoadValue(INI, MS, "M1", "../pictures/string6.png");
const char* string7 = IniLoadValue(INI, MS, "M1", "../pictures/string7.png");
const char* string8 = IniLoadValue(INI, MS, "M1", "../pictures/string8.png");
const char* string9 = IniLoadValue(INI, MS, "M1", "../pictures/string9.png");
const char* string10 = IniLoadValue(INI, MS, "M1", "../pictures/string10.png");
const char* string11 = IniLoadValue(INI, MS, "M1", "../pictures/string11.png");
const char* string12 = IniLoadValue(INI, MS, "M1", "../pictures/string12.png");
const char* string13 = IniLoadValue(INI, MS, "M1", "../pictures/string13.png");
const char* string14 = IniLoadValue(INI, MS, "M1", "../pictures/string14.png");
const char* string15 = IniLoadValue(INI, MS, "M1", "../pictures/string15.png");
const char* string16 = IniLoadValue(INI, MS, "M1", "../pictures/string16.png");
const char* string17 = IniLoadValue(INI, MS, "M1", "../pictures/string17.png");
const char* string18 = IniLoadValue(INI, MS, "M1", "../pictures/string18.png");
const char* string19 = IniLoadValue(INI, MS, "M1", "../pictures/string19.png");
const char* string20 = IniLoadValue(INI, MS, "M1", "../pictures/string20.png");
const char* string21 = IniLoadValue(INI, MS, "M1", "../pictures/string21.png");
const char* string22 = IniLoadValue(INI, MS, "M1", "../pictures/string22.png");
const char* string23 = IniLoadValue(INI, MS, "M1", "../pictures/string23.png");
const char* string24 = IniLoadValue(INI, MS, "M1", "../pictures/string24.png");
const char* string25 = IniLoadValue(INI, MS, "M1", "../pictures/string25.png");
const char* string26 = IniLoadValue(INI, MS, "M1", "../pictures/string26.png");
const char* string27 = IniLoadValue(INI, MS, "M1", "../pictures/string27.png");
const char* string28 = IniLoadValue(INI, MS, "M1", "../pictures/string28.png");
const char* string29 = IniLoadValue(INI, MS, "M1", "../pictures/string29.png");
const char* string30 = IniLoadValue(INI, MS, "M1", "../pictures/string30.png");
const char* string31 = IniLoadValue(INI, MS, "M1", "../pictures/string31.png");
const char* string32 = IniLoadValue(INI, MS, "M1", "../pictures/string32.png");
const char* string33 = IniLoadValue(INI, MS, "M1", "../pictures/string33.png");
const char* string34 = IniLoadValue(INI, MS, "M1", "../pictures/string34.png");
const char* string35 = IniLoadValue(INI, MS, "M1", "../pictures/string35.png");
const char* string36 = IniLoadValue(INI, MS, "M1", "../pictures/string36.png");
const char* string37 = IniLoadValue(INI, MS, "M1", "../pictures/string37.png");
const char* string38 = IniLoadValue(INI, MS, "M1", "../pictures/string38.png");
const char* string39 = IniLoadValue(INI, MS, "M1", "../pictures/string39.png");
const char* string40 = IniLoadValue(INI, MS, "M1", "../pictures/string40.png");
const char* string41 = IniLoadValue(INI, MS, "M1", "../pictures/string41.png");
const char* string42 = IniLoadValue(INI, MS, "M1", "../pictures/string42.png");
const char* string43 = IniLoadValue(INI, MS, "M1", "../pictures/string43.png");
const char* string44 = IniLoadValue(INI, MS, "M1", "../pictures/string44.png");
const char* string45 = IniLoadValue(INI, MS, "M1", "../pictures/string45.png");
const char* string46 = IniLoadValue(INI, MS, "M1", "../pictures/string46.png");
const char* string47 = IniLoadValue(INI, MS, "M1", "../pictures/string47.png");
const char* string48 = IniLoadValue(INI, MS, "M1", "../pictures/string48.png");
const char* string49 = IniLoadValue(INI, MS, "M1", "../pictures/string49.png");
const char* string50 = IniLoadValue(INI, MS, "M1", "../pictures/string50.png");
const char* string51 = IniLoadValue(INI, MS, "M1", "../pictures/string51.png");
const char* string52 = IniLoadValue(INI, MS, "M1", "../pictures/string52.png");
const char* string53 = IniLoadValue(INI, MS, "M1", "../pictures/string53.png");
const char* string54 = IniLoadValue(INI, MS, "M1", "../pictures/string54.png");
const char* string55 = IniLoadValue(INI, MS, "M1", "../pictures/string55.png");
const char* string56 = IniLoadValue(INI, MS, "M1", "../pictures/string56.png");
const char* string57 = IniLoadValue(INI, MS, "M1", "../pictures/string57.png");
const char* string58 = IniLoadValue(INI, MS, "M1", "../pictures/string58.png");
const char* string59 = IniLoadValue(INI, MS, "M1", "../pictures/string59.png");
const char* string60 = IniLoadValue(INI, MS, "M1", "../pictures/string60.png");
const char* string61 = IniLoadValue(INI, MS, "M1", "../pictures/string61.png");
const char* string62 = IniLoadValue(INI, MS, "M1", "../pictures/string62.png");
const char* string63 = IniLoadValue(INI, MS, "M1", "../pictures/string63.png");
const char* string64 = IniLoadValue(INI, MS, "M1", "../pictures/string64.png");
const char* string65 = IniLoadValue(INI, MS, "M1", "../pictures/string65.png");
const char* string66 = IniLoadValue(INI, MS, "M1", "../pictures/string66.png");
const char* string67 = IniLoadValue(INI, MS, "M1", "../pictures/string67.png");
const char* string68 = IniLoadValue(INI, MS, "M1", "../pictures/string68.png");
const char* string69 = IniLoadValue(INI, MS, "M1", "../pictures/string69.png");
const char* string70 = IniLoadValue(INI, MS, "M1", "../pictures/string70.png");
const char* string71 = IniLoadValue(INI, MS, "M1", "../pictures/string71.png");
const char* string72 = IniLoadValue(INI, MS, "M1", "../pictures/string72.png");
const char* string73 = IniLoadValue(INI, MS, "M1", "../pictures/string73.png");
const char* string74 = IniLoadValue(INI, MS, "M1", "../pictures/string74.png");
const char* string75 = IniLoadValue(INI, MS, "M1", "../pictures/string75.png");
const char* string76 = IniLoadValue(INI, MS, "M1", "../pictures/string76.png");
const char* string77 = IniLoadValue(INI, MS, "M1", "../pictures/string77.png");
const char* string78 = IniLoadValue(INI, MS, "M1", "../pictures/string78.png");
const char* string79 = IniLoadValue(INI, MS, "M1", "../pictures/string79.png");
const char* string80 = IniLoadValue(INI, MS, "M1", "../pictures/string80.png");
const char* string81 = IniLoadValue(INI, MS, "M1", "../pictures/string81.png");
const char* string82 = IniLoadValue(INI, MS, "M1", "../pictures/string82.png");
const char* string83 = IniLoadValue(INI, MS, "M1", "../pictures/string83.png");
const char* string84 = IniLoadValue(INI, MS, "M1", "../pictures/string84.png");
const char* string85 = IniLoadValue(INI, MS, "M1", "../pictures/string85.png");
const char* string86 = IniLoadValue(INI, MS, "M1", "../pictures/string86.png");
const char* string87 = IniLoadValue(INI, MS, "M1", "../pictures/string87.png");
const char* string88 = IniLoadValue(INI, MS, "M1", "../pictures/string88.png");
const char* string89 = IniLoadValue(INI, MS, "M1", "../pictures/string89.png");
const char* string90 = IniLoadValue(INI, MS, "M1", "../pictures/string90.png");
const char* string91 = IniLoadValue(INI, MS, "M1", "../pictures/string91.png");
const char* string92 = IniLoadValue(INI, MS, "M1", "../pictures/string92.png");
const char* string93 = IniLoadValue(INI, MS, "M1", "../pictures/string93.png");
const char* string94 = IniLoadValue(INI, MS, "M1", "../pictures/string94.png");
const char* string95 = IniLoadValue(INI, MS, "M1", "../pictures/string95.png");
const char* string96 = IniLoadValue(INI, MS, "M1", "../pictures/string96.png");
const char* string97 = IniLoadValue(INI, MS, "M1", "../pictures/string97.png");
const char* string98 = IniLoadValue(INI, MS, "M1", "../pictures/string98.png");
const char* string99 = IniLoadValue(INI, MS, "M1", "../pictures/string99.png");
const char* string100 = IniLoadValue(INI, MS, "M1", "../pictures/string100.png");



//月
int string1_M = IniLoadValue(INI, MN, "M1", 0);
int string2_M = IniLoadValue(INI, MN, "M2", 0);
int string3_M = IniLoadValue(INI, MN, "M3", 0);
int string4_M = IniLoadValue(INI, MN, "M4", 0);
int string5_M = IniLoadValue(INI, MN, "M5", 0);
int string6_M = IniLoadValue(INI, MN, "M6", 0);
int string7_M = IniLoadValue(INI, MN, "M7", 0);
int string8_M = IniLoadValue(INI, MN, "M8", 0);
int string9_M = IniLoadValue(INI, MN, "M9", 0);
int string10_M = IniLoadValue(INI, MN, "M10", 0);
int string11_M = IniLoadValue(INI, MN, "M11", 0);
int string12_M = IniLoadValue(INI, MN, "M12", 0);
int string13_M = IniLoadValue(INI, MN, "M13", 0);
int string14_M = IniLoadValue(INI, MN, "M14", 0);
int string15_M = IniLoadValue(INI, MN, "M15", 0);
int string16_M = IniLoadValue(INI, MN, "M16", 0);
int string17_M = IniLoadValue(INI, MN, "M17", 0);
int string18_M = IniLoadValue(INI, MN, "M18", 0);
int string19_M = IniLoadValue(INI, MN, "M19", 0);
int string20_M = IniLoadValue(INI, MN, "M20", 0);
int string21_M = IniLoadValue(INI, MN, "M21", 0);
int string22_M = IniLoadValue(INI, MN, "M22", 0);
int string23_M = IniLoadValue(INI, MN, "M23", 0);
int string24_M = IniLoadValue(INI, MN, "M24", 0);
int string25_M = IniLoadValue(INI, MN, "M25", 0);
int string26_M = IniLoadValue(INI, MN, "M26", 0);
int string27_M = IniLoadValue(INI, MN, "M27", 0);
int string28_M = IniLoadValue(INI, MN, "M28", 0);
int string29_M = IniLoadValue(INI, MN, "M29", 0);
int string30_M = IniLoadValue(INI, MN, "M30", 0);
int string31_M = IniLoadValue(INI, MN, "M31", 0);
int string32_M = IniLoadValue(INI, MN, "M32", 0);
int string33_M = IniLoadValue(INI, MN, "M33", 0);
int string34_M = IniLoadValue(INI, MN, "M34", 0);
int string35_M = IniLoadValue(INI, MN, "M35", 0);
int string36_M = IniLoadValue(INI, MN, "M36", 0);
int string37_M = IniLoadValue(INI, MN, "M37", 0);
int string38_M = IniLoadValue(INI, MN, "M38", 0);
int string39_M = IniLoadValue(INI, MN, "M39", 0);
int string40_M = IniLoadValue(INI, MN, "M40", 0);
int string41_M = IniLoadValue(INI, MN, "M41", 0);
int string42_M = IniLoadValue(INI, MN, "M42", 0);
int string43_M = IniLoadValue(INI, MN, "M43", 0);
int string44_M = IniLoadValue(INI, MN, "M44", 0);
int string45_M = IniLoadValue(INI, MN, "M45", 0);
int string46_M = IniLoadValue(INI, MN, "M46", 0);
int string47_M = IniLoadValue(INI, MN, "M47", 0);
int string48_M = IniLoadValue(INI, MN, "M48", 0);
int string49_M = IniLoadValue(INI, MN, "M49", 0);
int string50_M = IniLoadValue(INI, MN, "M50", 0);
int string51_M = IniLoadValue(INI, MN, "M51", 0);
int string52_M = IniLoadValue(INI, MN, "M52", 0);
int string53_M = IniLoadValue(INI, MN, "M53", 0);
int string54_M = IniLoadValue(INI, MN, "M54", 0);
int string55_M = IniLoadValue(INI, MN, "M55", 0);
int string56_M = IniLoadValue(INI, MN, "M56", 0);
int string57_M = IniLoadValue(INI, MN, "M57", 0);
int string58_M = IniLoadValue(INI, MN, "M58", 0);
int string59_M = IniLoadValue(INI, MN, "M59", 0);
int string60_M = IniLoadValue(INI, MN, "M60", 0);
int string61_M = IniLoadValue(INI, MN, "M61", 0);
int string62_M = IniLoadValue(INI, MN, "M62", 0);
int string63_M = IniLoadValue(INI, MN, "M63", 0);
int string64_M = IniLoadValue(INI, MN, "M64", 0);
int string65_M = IniLoadValue(INI, MN, "M65", 0);
int string66_M = IniLoadValue(INI, MN, "M66", 0);
int string67_M = IniLoadValue(INI, MN, "M67", 0);
int string68_M = IniLoadValue(INI, MN, "M68", 0);
int string69_M = IniLoadValue(INI, MN, "M69", 0);
int string70_M = IniLoadValue(INI, MN, "M70", 0);
int string71_M = IniLoadValue(INI, MN, "M71", 0);
int string72_M = IniLoadValue(INI, MN, "M72", 0);
int string73_M = IniLoadValue(INI, MN, "M73", 0);
int string74_M = IniLoadValue(INI, MN, "M74", 0);
int string75_M = IniLoadValue(INI, MN, "M75", 0);
int string76_M = IniLoadValue(INI, MN, "M76", 0);
int string77_M = IniLoadValue(INI, MN, "M77", 0);
int string78_M = IniLoadValue(INI, MN, "M78", 0);
int string79_M = IniLoadValue(INI, MN, "M79", 0);
int string80_M = IniLoadValue(INI, MN, "M80", 0);
int string81_M = IniLoadValue(INI, MN, "M81", 0);
int string82_M = IniLoadValue(INI, MN, "M82", 0);
int string83_M = IniLoadValue(INI, MN, "M83", 0);
int string84_M = IniLoadValue(INI, MN, "M84", 0);
int string85_M = IniLoadValue(INI, MN, "M85", 0);
int string86_M = IniLoadValue(INI, MN, "M86", 0);
int string87_M = IniLoadValue(INI, MN, "M87", 0);
int string88_M = IniLoadValue(INI, MN, "M88", 0);
int string89_M = IniLoadValue(INI, MN, "M89", 0);
int string90_M = IniLoadValue(INI, MN, "M90", 0);
int string91_M = IniLoadValue(INI, MN, "M91", 0);
int string92_M = IniLoadValue(INI, MN, "M92", 0);
int string93_M = IniLoadValue(INI, MN, "M93", 0);
int string94_M = IniLoadValue(INI, MN, "M94", 0);
int string95_M = IniLoadValue(INI, MN, "M95", 0);
int string96_M = IniLoadValue(INI, MN, "M96", 0);
int string97_M = IniLoadValue(INI, MN, "M97", 0);
int string98_M = IniLoadValue(INI, MN, "M98", 0);
int string99_M = IniLoadValue(INI, MN, "M99", 0);
int string100_M = IniLoadValue(INI, MN, "M100", 0);



//座標
int CharaX = IniLoadValue(INI, "Position", "CharaX", 280);
int CharaY = IniLoadValue(INI, "Position", "CharaY", 0);
int MessageWindowX = IniLoadValue(INI, "Position", "MessageWindowX", 0);
int MessageWindowY = IniLoadValue(INI, "Position", "MessageWindowY", 0);
int MessageX = IniLoadValue(INI, "Position", "MessageX", 0);
int MessageY = IniLoadValue(INI, "Position", "MessageY", 0);
