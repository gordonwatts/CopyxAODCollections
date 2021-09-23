# Build a docker image to run against ATLAS code that has been pre-built and is ready to go.

FROM atlas/analysisbase:21.2.184

WORKDIR /home/atlas

# Turn this on so that stdout isn't buffered - otherwise logs in kubectl don't
# show up until much later!
ENV PYTHONUNBUFFERED=1

# Copy over the source
COPY copyfiles.cxx .

# By default, run it!
ENTRYPOINT [ "bash", "-c", "source ./release_setup.sh; root -b $ROOTCOREDIR/scripts/load_packages.C ./copyfiles.cxx" ]
