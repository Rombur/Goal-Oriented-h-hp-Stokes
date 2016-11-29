#! /usr/bin/env python
#----------------------------------------------------------------------------#
# Python code
# Author: Bruno Turcksin
# Date: 2015-10-08 17:26:27.786019
#----------------------------------------------------------------------------#

import pylab

input_files = ['goal-error-ex3-hp099-meanVelocity-RHS.txt', 'goal-est-ex3-hp099-meanVelocity-RHS.txt']
output_file = 'convergence.png'

colors = ['blue', 'red', 'green', 'black']
line_widths = 2.
line_styles = '-'
markers = 'D'
marker_sizes = 7
legend = []


pylab.figure(1)
for i in xrange(len(input_files)):
  f = open(input_files[i],'r')
  data = f.read().split()
  n_dofs = []
  error = []
  pos = 0;
  example = data[pos]
  pos += 1
  if (data[pos]=='goal-err'):
    refinement = 'Goal-Oriented Error '
  elif (data[pos]=='goal-est'):
    refinement = 'Goal-Oriented Estimator'
  else:
    refinement = 'hp_ref: '
  pos += 1
  refinement += data[pos]
  legend.append(refinement)
  pos += 1
  while pos<len(data):
    n_dofs.append(float(data[pos]))
    pos += 1
    error.append(float(data[pos]))
    pos += 1
  pylab.loglog(n_dofs, error, colors[i], linewidth=line_widths, 
      linestyle=line_styles, marker=markers, markersize=marker_sizes)


pylab.xlabel('Number of degrees of freedom')
pylab.ylabel('gaol-orinted error')
pylab.legend(legend)
pylab.savefig(output_file)
