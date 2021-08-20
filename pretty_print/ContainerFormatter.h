#pragma once

#include<iosfwd>
#include<string>
#include<string_view>

template<typename T>
class SeqFormatter
{
public:
  SeqFormatter(const T& i_cont) : d_cont(i_cont) {}
  SeqFormatter(const SeqFormatter&) = delete;
  SeqFormatter() = delete;
  const SeqFormatter& operator = (const SeqFormatter&) = delete;
  SeqFormatter& setDelimiters(std::string_view i_left, std::string_view i_right)
  {
    d_leftDelim = i_left;
    d_rightDelim = i_right;
    return *this;
  }
  SeqFormatter& setSep(std::string_view i_sep)
  {
    d_sep = i_sep;
    return *this;
  }
  friend std::ostream& operator << (std::ostream& os, const SeqFormatter& i_formatter)
  {
    os << i_formatter.d_leftDelim;
    auto startIt = i_formatter.d_cont.cbegin();
    auto endIt = i_formatter.d_cont.cend();
    if (startIt != endIt)
    {
      os << *startIt;
      ++startIt;
    }
    while (startIt != endIt)
    {
      os << i_formatter.d_sep << *startIt;
      ++startIt;
    }
    os << i_formatter.d_rightDelim;
    return os;
  }
private:
  std::string d_rightDelim = "}";
  std::string d_leftDelim = "{";
  std::string d_sep = ", ";
  const T& d_cont;
};


template<typename T>
class DictFormatter
{
public:
  DictFormatter(const T& i_cont) : d_cont(i_cont) {}
  DictFormatter(const DictFormatter&) = delete;
  DictFormatter() = delete;
  const DictFormatter& operator = (const DictFormatter&) = delete;
  DictFormatter& setDelimiters(std::string_view i_left, std::string_view i_right)
  {
    d_leftDelim = i_left;
    d_rightDelim = i_right;
    return *this;
  }
  DictFormatter& setSep(std::string_view i_sep)
  {
    d_sep = i_sep;
    return *this;
  }
  DictFormatter& setMap(std::string_view i_map)
  {
    d_map = i_map;
    return *this;
  }
  friend std::ostream& operator << (std::ostream& os, const DictFormatter& i_formatter)
  {
    os << i_formatter.d_leftDelim;
    auto startIt = i_formatter.d_cont.cbegin();
    auto endIt = i_formatter.d_cont.cend();
    if (startIt != endIt)
    {
      os << startIt->first << i_formatter.d_map << startIt->second;
      ++startIt;
    }
    while (startIt != endIt)
    {
      os << i_formatter.d_sep << startIt->first << i_formatter.d_map << startIt->second;
      ++startIt;
    }
    os << i_formatter.d_rightDelim;
    return os;
  }
private:
  std::string d_rightDelim = "}";
  std::string d_leftDelim = "{";
  std::string d_sep = ", ";
  std::string d_map = " -> ";
  const T& d_cont;
};




