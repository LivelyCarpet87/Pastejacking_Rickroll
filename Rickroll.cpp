/*
    A program that replaces the links to certain websites with rickrolls in the MacOS system clipboard using built-in binaries. 
    Copyright (C) 2020  Tyllis Xu

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <unistd.h>
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <array>
#include <signal.h>
#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <regex>

using namespace std;

std::string exec(const char * cmd) {
  std::array < char, 128 > buffer;
  std::string result;
  std::unique_ptr < FILE, decltype( & pclose) > pipe(popen(cmd, "r"), pclose);
  if (!pipe) {
    throw std::runtime_error("popen() failed!");
  }
  while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
  }
  return result;
}

int main(){

while (1 == 1){
string clip = exec("pbpaste");
if ((rand() % 7) == 1) {

std::regex long_r ("(youtube.com/watch\\?v=)[a-zA-Z0-9\-\_]{11}");
clip = regex_replace(clip, long_r, "$1dQw4w9WgXcQ");

std::regex short_r ("(youtu.be/)[a-zA-Z0-9\-\_]{11}");
clip = regex_replace(clip, short_r, "$1dQw4w9WgXcQ");

std::regex googledrive ("(drive.google.com/file/d/)[a-zA-Z0-9\-\_]{28}");
clip = regex_replace(clip, googledrive, "$010B7g1h4sDEtjuZy1lWDBmTlBwZlk");

std::regex tinyurl ("(http://tinyurl.com/)[a-zA-Z0-9\-\_]{6}");
clip = regex_replace(clip, tinyurl, "$012g9mqh");

std::regex alturl ("(alturl.com/)[a-zA-Z0-9\-\_]{5}");
clip = regex_replace(clip, alturl, "$01p749b");

std::regex bitly ("(bit.ly/)[a-zA-Z0-9\-\_]{7}");
clip = regex_replace(clip, bitly, "$013bwvRSg");

exec(string("printf \"" + clip+ "\"| pbcopy").c_str());
}
sleep(7);

}

}
