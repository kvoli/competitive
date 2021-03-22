#include <bits/stdc++.h>
using namespace std;
class FileSystem {
  public:
  FileSystem()
  {
    dirMap["/"] = set<string>();
  }

  vector<string> ls(string path)
  {
    return vector<string>(dirMap[path].begin(), dirMap[path].end());
  }

  void mkdir(string path)
  {
    vector<string> tokens;
    tokenize(path, tokens);
    int i, n;
    n = tokens.size();
    string dir = "";
    string prev = "/";
    for (i = 0; i < n; ++i) {
      dir += "/";
      dir += tokens[i];
      if (dirMap.find(dir) == dirMap.end()) {
        dirMap[dir] = set<string>();
        dirMap[prev].insert(tokens[i]);
      }
      prev = dir;
    }
  }

  void addContentToFile(string filePath, string content)
  {
    mkdir(filePath);
    dirMap[filePath].insert(getFileName(filePath));
    contentMap[filePath] += content;
  }

  string getFileName(string& filePath)
  {
    int n, i;
    n = filePath.size();
    for (i = n - 1; i >= 0 && filePath[i] != '/'; --i)
      ;
    return filePath.substr(i + 1);
  }

  string readContentFromFile(string filePath)
  {
    return contentMap[filePath];
  }

  private:
  unordered_map<string, set<string>> dirMap;
  unordered_map<string, string> contentMap;

  void tokenize(string& in, vector<string>& out)
  {
    replace(begin(in), end(in), '/', ' ');
    string tmp;
    stringstream ss(in);
    while (ss >> tmp)
      out.push_back(tmp);
  }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
