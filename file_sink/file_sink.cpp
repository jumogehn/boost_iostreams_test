
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/stream.hpp>

typedef boost::iostreams::stream<boost::iostreams::file_sink> ofstream;

int main()
{
  ofstream out("HeavyArtillery.txt"); // Wilfred Owen
  out << "Reach at that Arrogance which needs thy harm,\n"
    "And beat it down before its sins grow worse.\n";
  out.close();

  return 0;
}

