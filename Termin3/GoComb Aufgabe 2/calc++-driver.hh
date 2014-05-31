#ifndef CALCXX_DRIVER_HH
# define CALCXX_DRIVER_HH
# include <string>
# include <map>
# include <fstream>
# include "calc++-parser.hh"

// Tell Flex the lexer's prototype ...
# define YY_DECL \
  yy::calcxx_parser::symbol_type yylex (calcxx_driver& driver)
// ... and declare it for the parser's sake.
YY_DECL;

// Conducting the whole scanning and parsing of Calc++.
class calcxx_driver
{
public:
  calcxx_driver ();
  virtual ~calcxx_driver ();

  std::map<std::string, float> variables;
  std::map<std::string, std::string> nodes;
  std::string node1, node2;
  float val1, val2;
  float result;

  // Handling the scanner.
  void scan_begin ();
  void scan_end ();
  bool trace_scanning;

  // Run the parser on file F.
  // Return 0 on success.
  float parse (const std::string& f);
  // The name of the file being parsed.
  // Used later to pass the file name to the location tracker.
  std::string file;
  // Whether parser traces should be generated.
  bool trace_parsing;
  std::string lastID;
  
  //Graph erstellen
  std::string getNewID();
  void setTmpID (std::string id);
  std::string getTmpID();
  void connect(std::string n1, std::string n2);
  std::string addGraph(std::string label);
  std::string addGraph(float label);

  void addGraph(std::string name, float value);
  
  float getVariable(std::string name);
  
  // Error handling.
  void error (const yy::location& l, const std::string& m);
  void error (const std::string& m);
private:
  static int nodeCount;
  std::ofstream o;
  std::string tmpID;
};
#endif // ! CALCXX_DRIVER_HH
