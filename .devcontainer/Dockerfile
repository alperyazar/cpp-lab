FROM mcr.microsoft.com/devcontainers/base:debian-13

# Install gcc, g++, and build utilities
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    && rm -rf /var/lib/apt/lists/*

# Claude Code:
USER vscode
RUN curl -fsSL https://claude.ai/install.sh | bash
USER root
