## Docker
```shell
docker run -d --entrypoint bash --gpus all --name kexin-env -v /home/kec23008/docker-sys/moe-sys:/workspace moe-sys -c "tail -f /dev/null"
```


```shell
sudo apt update
sudo apt install python3.11

# 手动安装wget
sudo apt-get install wget

# 手动安装pip
wget https://bootstrap.pypa.io/get-pip.py
python3.11 get-pip.py

# install transformers, torch（cuda 12.4）
python3.11 -m pip install transformers torch torchvision torchaudio accelerate
# new model
python3.11 -m pip install joblib scikit-learn
# int4
python3.11 -m pip install optimum auto_gptq
# is_torch_greater_or_equal_than_1_13
vim /usr/local/lib/python3.11/dist-packages/transformers/pytorch_utils.py

# 修改文件
cd /workspace/

# backup modeling outputs
sudo cp /usr/local/lib/python3.11/dist-packages/transformers/modeling_outputs.py /usr/local/lib/python3.11/dist-packages/transformers/modeling_outputs_bak.py
sudo cp ./qwen2_moe/modeling_outputs.py /usr/local/lib/python3.11/dist-packages/transformers/

# replace
sudo cp /usr/local/lib/python3.11/dist-packages/transformers/models/qwen2_moe/modeling_qwen2_moe.py /usr/local/lib/python3.11/dist-packages/transformers/models/qwen2_moe/modeling_qwen2_moe_bak.py
sudo cp ./qwen2_moe/modeling_qwen2_moe.py /usr/local/lib/python3.11/dist-packages/transformers/models/qwen2_moe/
sudo cp ./qwen2_moe/moe_predict_model.py /usr/local/lib/python3.11/dist-packages/transformers/models/qwen2_moe/
sudo cp ./qwen2_moe/expert_memory_manager.py /usr/local/lib/python3.11/dist-packages/transformers/models/qwen2_moe/

# workspace
cd /workspace/MoE-ICML/
```