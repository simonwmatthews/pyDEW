FROM registry.gitlab.com/enki-portal/thermoengine:master
COPY . ${HOME}/pyDEW/
USER root
RUN git clone https://gitlab.com/ENKI-portal/SUPCRTandEQs.git
RUN cd SUPCRTandEQs && git checkout DEW_activities && git pull
RUN cp pyDEW/f2c_makefiles/Makefile_linux SUPCRTandEQs/f2c/libf2c/Makefile
RUN chmod u+x SUPCRTandEQs/f2c_build.sh
RUN cd SUPCRTandEQs && ./f2c_build.sh
RUN cd SUPCRTandEQs && make
RUN rm -r SUPCRTandEQs
RUN chown -R ${NB_UID} ${HOME}
RUN cd pyDEW && pip install .
# RUN cd pyDEW && mkdir temp/
# RUN cd pyDEW && cp trigger_compilation.py temp/trigger_compilation.py
# RUN cd pyDEW/temp && ipython trigger_compilation.py
# RUN rm -r pyDEW/temp
USER ${NB_UID}
# RUN cp -r pyDEW/tutorials tutorials
