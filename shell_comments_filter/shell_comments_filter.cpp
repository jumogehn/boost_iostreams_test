
#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <shell_comments_filter.hpp>

namespace io      = boost::iostreams;
namespace example = boost::iostreams::example;

int main()
{
  io::filtering_ostream out;
  out.push(example::shell_comments_output_filter());
  out.push(io::file_sink("shell_comments_output_filter.txt"));

  out << ""
    "# ~/.bashrc: executed by bash(1) for non-login shells.\n"
    "# see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)\n"
    "# for examples\n"
    "\n"
    "# If not running interactively, don't do anything\n"
    "[ -z \"$PS1\" ] && return\n"
    "\n"
    "# don't put duplicate lines or lines starting with space in the history.\n"
    "# See bash(1) for more options\n"
    "HISTCONTROL=ignoreboth\n"
    "\n"
    "# append to the history file, don't overwrite it\n"
    "shopt -s histappend\n"
    "\n"
    "# for setting history length see HISTSIZE and HISTFILESIZE in bash(1)\n"
    "HISTSIZE=1000\n"
    "HISTFILESIZE=2000\n"
    "\n"
    "# check the window size after each command and, if necessary,\n"
    "# update the values of LINES and COLUMNS.\n"
    "shopt -s checkwinsize\n"
    "\n"
    "# If set, the pattern \"**\" used in a pathname expansion context will\n"
    "# match all files and zero or more directories and subdirectories.\n"
    "#shopt -s globstar\n"
    "\n"
    "# make less more friendly for non-text input files, see lesspipe(1)\n"
    "[ -x /usr/bin/lesspipe ] && eval \"$(SHELL=/bin/sh lesspipe)\"\n";

  return 0;
}

