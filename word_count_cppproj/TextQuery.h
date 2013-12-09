#ifndef TEXTQUERY_H
#define TEXTQUERY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <set>
#include <map>

using namespace std;

class TextQuery
{
public:
	typedef vector<string>::size_type line_no;
	/* 接口说明
	 *		read_file 为输入文件创建数据结构
	 *		run_query 查找指定词,并返回一个set包含所有他出现的行
	 *		text_line 返回输入文件中指定的一行
	 */
	void read_file(ifstream &is)
	{ store_file(is); build_map(); }
	set<line_no> run_query(const string& ) const;
	string text_line(line_no) const;
private:
	void store_file(ifstream &); //储存input file
	void build_map(); // 为每个词语关联到他出现的行,用set储存
	// 记录整个输入文件
	vector<string> lines_of_text;
	// 记录词语以及他们出现的所有行
	map<string, set<line_no>> word_map;
};




#endif