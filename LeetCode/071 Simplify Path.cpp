class Solution {
 
 public:
   
   std::string simplifyPath(std::string path) {
    std::vector<std::string> directories;
    std::string directory;
    for (size_t i = 0; ; ++i) {
      char c = path[i];
      if (c == '/' || !c) {
        if (directory == "" || directory == ".") {
        } else if (directory == "..") {
          if (directories.size()) {
            directories.pop_back();
          }
        } else {
          directories.push_back(directory);
        }
        directory = "";
      } else {
        directory += c;
      }
      if (!c) {
        break;
      }
    }
    std::string new_path = "";
    for (std::string &d : directories) {
      new_path += "/" + d;
    }
    return (new_path == "") ? "/" : new_path;
  }

};
