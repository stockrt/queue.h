#!/usr/bin/env ruby

# Created: May 15, 2013
# Author: Rogério Carvalho Schneider <stockrt@gmail.com>

o = File.open('pad.txt', 'wt')
File.open('queue.h', 'rt').each_line do |line|
  if line =~ / \\$/
    line['\\'] = ' ' * (79 - line.length) + '\\'
  end
  o.write(line)
end
o.close
