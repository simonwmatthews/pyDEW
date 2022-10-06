FROM registry.gitlab.com/enki-portal/thermoengine:master
COPY . ${HOME}
USER root
RUN chown -R ${NB_UID} ${HOME}
RUN pip install .
RUN mkdir temp/
RUN cp trigger_compilation.py temp/trigger_compilation.py
RUN cd temp && ipython trigger_compilation.py
USER ${NB_USER}
