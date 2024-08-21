# Use an official Ubuntu as a parent image
FROM ubuntu:20.04

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    git \
    python3 \
    python3-pip \
    python3-dev \
    libcurl4-openssl-dev \
    libjsoncpp-dev

# Install Python packages
RUN pip3 install pandas numpy matplotlib requests

# Create app directory
WORKDIR /app

# Copy the current directory contents into the container at /app
COPY . /app

# Command to run the application
CMD ["bash"]
