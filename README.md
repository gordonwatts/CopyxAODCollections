# CopyxAODCollections
Simple docker container to copy out a few events and collections

A very simple ROOT C++ script that will copy over some number of events and write out the collections
you want to a new file.

It is currently hardwired to:

- Copy over the first 10 events
- Only copy over the 'AntiKt4EMTopoJets' collection.

## Usage:

Running this container to do the work is a matter of specifying an input file and an output directory and mapping them to your
host system:

```
docker run --rm -v <path-to-xaod-file>:/data/inputfile.root -v <path-to-output-directory>:/output  gordonwatts/copyxaodcollections:latest
```

## Building

Docker build command is fairly straight forward:

```
docker build --rm -f "Dockerfile" -t gordonwatts/copyxaodcollections:latest .
```

It is also kept up to date on [docker hub]().

## Ack

Thanks to Nils Krumnack for the code upon which this is based.
