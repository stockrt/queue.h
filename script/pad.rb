#!/usr/bin/env ruby

o = File.open('pad.txt', 'wt')
File.open('queue.h', 'rt').each_line do |line|
  if line =~ / \\$/
    line['\\'] = ' ' * (79 - line.length) + '\\'
  end
  o.write(line)
end
o.close
